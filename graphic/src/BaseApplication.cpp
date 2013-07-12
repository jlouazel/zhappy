/*
-----------------------------------------------------------------------------
Filename:    BaseApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/

#define RAYON   810

#include "BaseApplication.h"
#include <iostream>
#include <math.h>
#include "Graphic.hh"
#include "Treatment.hh"
#include "eRessources.hh"
#include "Players.hh"

extern GraphicClient *client;

//-------------------------------------------------------------------------------------
BaseApplication::BaseApplication(void)
    : mRoot(0),
      mCamera(0),
      mSceneMgr(0),
      mWindow(0),
      mResourcesCfg(Ogre::StringUtil::BLANK),
      mPluginsCfg(Ogre::StringUtil::BLANK),
      mTrayMgr(0),
      mCameraMan(0),
      mDetailsPanel(0),
      mCursorWasVisible(false),
      mShutDown(false),
      mInputManager(0),
      mMouse(0),
      mKeyboard(0)
{
  this->farDistance = 1000;
  std::cout << this->farDistance << std::endl;
}

//-------------------------------------------------------------------------------------
BaseApplication::~BaseApplication(void)
{
  if (mTrayMgr) delete mTrayMgr;
  if (mCameraMan) delete mCameraMan;

    //Remove ourself as a Window listener
    Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
    windowClosed(mWindow);
    delete mRoot;
}

//-------------------------------------------------------------------------------------
bool BaseApplication::configure(void)
{
    // Show the configuration dialog and initialise the system
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg
    if(mRoot->showConfigDialog())
    {
        // If returned true, user clicked OK so initialise
        // Here we choose to let the system create a default rendering window by passing 'true'
        mWindow = mRoot->initialise(true, "TutorialApplication Render Window");

        return true;
    }
    else
    {
        return false;
    }
}
//-------------------------------------------------------------------------------------
void BaseApplication::chooseSceneManager(void)
{
    // Get the SceneManager, in this case a generic one
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
}
//-------------------------------------------------------------------------------------
void BaseApplication::createCamera(void)
{
    // Create the camera
    mCamera = mSceneMgr->createCamera("PlayerCam");

    // Position it at 500 in Z direction
    mCamera->setPosition(Ogre::Vector3(0,0,80));
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0,0,-300));
    mCamera->setNearClipDistance(1);
    //    mCamera->setFarClipDistance(1200);

    mCameraMan = new OgreBites::SdkCameraMan(mCamera);   // create a default camera controller
    mCameraMan->setTopSpeed(1000);
}
//-------------------------------------------------------------------------------------
void BaseApplication::createFrameListener(void)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;

    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    mInputManager = OIS::InputManager::createInputSystem( pl );

    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));

    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);

    //Set initial mouse clipping size
    windowResized(mWindow);

    //Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

    mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", mWindow, mMouse, this);
    mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    // mTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
    mTrayMgr->hideCursor();

    //    create a params panel for displaying sample details
    // Ogre::StringVector items;
    // items.push_back("cam.pX");
    // items.push_back("cam.pY");
    // items.push_back("cam.pZ");
    // items.push_back("");
    // items.push_back("cam.oW");
    // items.push_back("cam.oX");
    // items.push_back("cam.oY");
    // items.push_back("cam.oZ");
    // items.push_back("");
    // items.push_back("Filtering");
    // items.push_back("Poly Mode");

    // mDetailsPanel = mTrayMgr->createParamsPanel(OgreBites::TL_NONE, "DetailsPanel", 200, items);
    // mDetailsPanel->setParamValue(9, "Bilinear");
    // mDetailsPanel->setParamValue(10, "Solid");
    // mDetailsPanel->hide();
    
    mRoot->addFrameListener(this);
}
//-------------------------------------------------------------------------------------
void BaseApplication::destroyScene(void)
{
}

void BaseApplication::createViewports(void)
{
    // Create one viewport, entire window
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(
        Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}

//-------------------------------------------------------------------------------------
void BaseApplication::setupResources(void)
{
    // Load resource paths from config file
    Ogre::ConfigFile cf;
    cf.load(mResourcesCfg);

    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
            // OS X does not set the working directory relative to the app,
            // In order to make things portable on OS X we need to provide
            // the loading with it's own bundle path location
            if (!Ogre::StringUtil::startsWith(archName, "/", false)) // only adjust relative dirs
                archName = Ogre::String(Ogre::macBundlePath() + "/Contents/Resources/" + archName);
#endif
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }
}
//-------------------------------------------------------------------------------------
void BaseApplication::createResourceListener(void)
{

}
//-------------------------------------------------------------------------------------
void BaseApplication::loadResources(void)
{
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
//-------------------------------------------------------------------------------------
void BaseApplication::go(void)
{
#ifdef _DEBUG
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS || OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    Ogre::String workingDir = Ogre::macBundlePath()+"/Contents/Resources/";
    mResourcesCfg = workingDir + mResourcesCfg;
    mPluginsCfg = workingDir + mPluginsCfg;
#endif

    if (!setup())
        return;

    mRoot->startRendering();

    // clean up
    destroyScene();
}
//-------------------------------------------------------------------------------------
bool BaseApplication::setup(void)
{
    mRoot = new Ogre::Root(mPluginsCfg);

    setupResources();

    bool carryOn = configure();
    if (!carryOn) return false;

    chooseSceneManager();
    createCamera();
    createViewports();

    // Set default mipmap level (NB some APIs ignore this)
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

    // Create any resource listeners (for loading screens)
    createResourceListener();
    // Load resources
    loadResources();

    // Create the scene
    createScene();

    createFrameListener();

    return true;
};

static std::string toString(int number)
{
  std::stringstream ss;

  ss << number;
  return ss.str();
}

static void DestroyAllAttachedMovableObjects( Ogre::SceneNode* i_pSceneNode )
{
  if ( !i_pSceneNode )
    return;

  // Destroy all the attached objects
  Ogre::SceneNode::ObjectIterator itObject = i_pSceneNode->getAttachedObjectIterator();

  while ( itObject.hasMoreElements() )
    {
      MovableObject* pObject = static_cast<MovableObject*>(itObject.getNext());
      i_pSceneNode->getCreator()->destroyMovableObject( pObject );
    }

  // Recurse to child SceneNodes
  Ogre::SceneNode::ChildNodeIterator itChild = i_pSceneNode->getChildIterator();

  while ( itChild.hasMoreElements() )
    {
      SceneNode* pChildNode = static_cast<SceneNode*>(itChild.getNext());
      DestroyAllAttachedMovableObjects(pChildNode);
    }
}

//-------------------------------------------------------------------------------------

bool BaseApplication::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    parseRead(client, client->readOnServer());

    //Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    mTrayMgr->frameRenderingQueued(evt);

    if (!mTrayMgr->isDialogVisible())
      {
        mCameraMan->frameRenderingQueued(evt);   // if dialog isn't up, then update the camera
        // if (mDetailsPanel->isVisible())   // if details panel is visible, then update its contents
        // {
        //     mDetailsPanel->setParamValue(0, Ogre::StringConverter::toString(mCamera->getDerivedPosition().x));
        //     mDetailsPanel->setParamValue(1, Ogre::StringConverter::toString(mCamera->getDerivedPosition().y));
        //     mDetailsPanel->setParamValue(2, Ogre::StringConverter::toString(mCamera->getDerivedPosition().z));
        //     mDetailsPanel->setParamValue(4, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().w));
        //     mDetailsPanel->setParamValue(5, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().x));
        //     mDetailsPanel->setParamValue(6, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().y));
        //     mDetailsPanel->setParamValue(7, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().z));
        // }
      }

    for (std::vector<Square *>::const_iterator it = client->getWorld()->getMap().begin(); it != client->getWorld()->getMap().end(); ++it)
      {
	std::string meshToAttach = "0";
	if ((*it)->getContent()[LINEMATE])
	  meshToAttach += "1";
	else
	  meshToAttach += "0";
	if ((*it)->getContent()[DERAUMERE])
	  meshToAttach += "1";
	else
	  meshToAttach += "0";
	if ((*it)->getContent()[SIBUR])
	  meshToAttach += "1";
	else
	  meshToAttach += "0";
	if ((*it)->getContent()[MENDIANE])
	  meshToAttach += "1";
	else
	  meshToAttach += "0";
	if ((*it)->getContent()[PHIRAS])
	  meshToAttach += "1";
	else
	  meshToAttach += "0";
	if ((*it)->getContent()[THYSTAME])
	  meshToAttach += "1";
	else
	  meshToAttach += "0";
	meshToAttach += ".mesh";
	Ogre::SceneNode* squareNode;
	if (!mSceneMgr->hasSceneNode("Square_" + toString((*it)->getX()) + "_" + toString((*it)->getY())))
	  {
	    squareNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("Square_" + toString((*it)->getX()) + "_" + toString((*it)->getY()));
	    squareNode->setPosition(sin((*it)->getX() * 2 * M_PI / client->getWorld()->getWidth()) * RAYON, 0, cos((*it)->getX() * 2 * M_PI / client->getWorld()->getWidth()) * RAYON);
	    squareNode->yaw(Ogre::Radian((*it)->getX() * 2 * M_PI / client->getWorld()->getWidth()));
	    squareNode->pitch(Ogre::Radian((*it)->getY() * 2 * M_PI / client->getWorld()->getHeight()));
	    squareNode->translate(0, 365, 0, Ogre::Node::TS_LOCAL);
	    float   scale;
	    scale = 1000.0 / static_cast<float>(client->getWorld()->getWidth() * client->getWorld()->getHeight()) ;
	    scale = sqrt(scale);                                                                          
	    scale *= (sin((*it)->getY() * 2 * M_PI / client->getWorld()->getHeight()) / 5 + 1.5) * 0.4;                                          
	    squareNode->setScale(scale, scale, scale);
	  }
	else
	  {
	    squareNode = mSceneMgr->getSceneNode("Square_" + toString((*it)->getX()) + "_" + toString((*it)->getY()));
	    //	    squareNode->detachAllObjects();
	    DestroyAllAttachedMovableObjects(squareNode);	    
	  }
	if (meshToAttach != "0000000.mesh")
	  {
	    //		std::cout << meshToAttach << std::endl;
	    Ogre::Entity* mesh = mSceneMgr->createEntity(meshToAttach);
	    squareNode->attachObject(mesh);
	  }                          
	//	std::cout << (*it)->getContent()[FOOD] << std::endl;
	if ((*it)->getContent()[FOOD])
	  {
	    Ogre::Entity* mesh = mSceneMgr->createEntity("Food.mesh");
	    squareNode->attachObject(mesh);		    
	  }	
      }

    std::cout << "LOL1" << std::endl;

    for (std::map<int, Players * >::iterator it = client->getPlayers().begin(); it != client->getPlayers().end(); ++it)
      {
	Ogre::SceneNode* playerNode;
	int i = it->first;
	Players *p = it->second;
	std::cout << i <<  " : x : " << p->getX() << "; y = " << p->getY() << std::endl;
	if (p->getNode() == 0)
	  {
	    playerNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("Player_" + toString(i));
	    p->setNode(playerNode);
	    Ogre::Entity* mesh = mSceneMgr->createEntity("Krusty.mesh");
	    playerNode->attachObject(mesh);
	  }
	else
	  playerNode = p->getNode();
	playerNode->resetToInitialState();
	playerNode->setPosition(sin(p->getX() * 2 * M_PI / client->getWorld()->getWidth()) * RAYON, 0, cos(p->getX() * 2 * M_PI / client->getWorld()->getWidth()) * RAYON);
	playerNode->yaw(Ogre::Radian(p->getX() * 2 * M_PI / client->getWorld()->getWidth()));
	playerNode->pitch(Ogre::Radian(p->getY() * 2 * M_PI / client->getWorld()->getHeight()));
	playerNode->translate(0, 365, 0, Ogre::Node::TS_LOCAL);
	float   scale;
	scale = 1000.0 / static_cast<float>(client->getWorld()->getWidth() * client->getWorld()->getHeight()) ;
	scale = sqrt(scale);                                                                          
	scale *= (sin(p->getY() * 2 * M_PI / client->getWorld()->getHeight()) / 5 + 1.5) * 0.4;                                          
	playerNode->setScale(scale, scale, scale);
      }

    std::cout << "LOL2" << std::endl;

    return true;
}

bool BaseApplication::keyPressed( const OIS::KeyEvent &arg )
{
    if (mTrayMgr->isDialogVisible()) return true;   // don't process any more keys if dialog is up

    if (arg.key == OIS::KC_F)   // toggle visibility of advanced frame stats
    {
        mTrayMgr->toggleAdvancedFrameStats();
    }
    else if (arg.key == OIS::KC_G)   // toggle visibility of even rarer debugging details
    {
      if (mDetailsPanel->getTrayLocation() == OgreBites::TL_NONE)
        {
	  mTrayMgr->moveWidgetToTray(mDetailsPanel, OgreBites::TL_TOPRIGHT, 0);
	  mDetailsPanel->show();
        }
      else
	{
	  mTrayMgr->removeWidgetFromTray(mDetailsPanel);
	  mDetailsPanel->hide();
	}
    }
    else if (arg.key == OIS::KC_T)   // cycle polygon rendering mode
    {
        Ogre::String newVal;
        Ogre::TextureFilterOptions tfo;
        unsigned int aniso;

        switch (mDetailsPanel->getParamValue(9).asUTF8()[0])
        {
        case 'B':
            newVal = "Trilinear";
            tfo = Ogre::TFO_TRILINEAR;
            aniso = 1;
            break;
        case 'T':
            newVal = "Anisotropic";
            tfo = Ogre::TFO_ANISOTROPIC;
            aniso = 8;
            break;
        case 'A':
            newVal = "None";
            tfo = Ogre::TFO_NONE;
            aniso = 1;
            break;
        default:
            newVal = "Bilinear";
            tfo = Ogre::TFO_BILINEAR;
            aniso = 1;
        }

        Ogre::MaterialManager::getSingleton().setDefaultTextureFiltering(tfo);
        Ogre::MaterialManager::getSingleton().setDefaultAnisotropy(aniso);
        mDetailsPanel->setParamValue(9, newVal);
    }
    else if (arg.key == OIS::KC_R)   // cycle polygon rendering mode
    {
        Ogre::String newVal;
        Ogre::PolygonMode pm;

        switch (mCamera->getPolygonMode())
        {
        case Ogre::PM_SOLID:
            newVal = "Wireframe";
            pm = Ogre::PM_WIREFRAME;
            break;
        case Ogre::PM_WIREFRAME:
            newVal = "Points";
            pm = Ogre::PM_POINTS;
            break;
        default:
            newVal = "Solid";
            pm = Ogre::PM_SOLID;
        }

        mCamera->setPolygonMode(pm);
        mDetailsPanel->setParamValue(1, newVal);
    }
    else if(arg.key == OIS::KC_F5)   // refresh all textures
    {
        Ogre::TextureManager::getSingleton().reloadAll();
    }
    else if (arg.key == OIS::KC_SYSRQ)   // take a screenshot
    {
        mWindow->writeContentsToTimestampedFile("screenshot", ".jpg");
    }
    else if (arg.key == OIS::KC_ESCAPE)
    {
        mShutDown = true;
    }

    mCameraMan->injectKeyDown(arg);
    return true;
}

bool BaseApplication::keyReleased( const OIS::KeyEvent &arg )
{
    mCameraMan->injectKeyUp(arg);
    return true;
}

bool BaseApplication::mouseMoved( const OIS::MouseEvent &arg )
{
    if (mTrayMgr->injectMouseMove(arg)) return true;
    mCameraMan->injectMouseMove(arg);
    return true;
}

bool BaseApplication::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    if (mTrayMgr->injectMouseDown(arg, id)) return true;
    mCameraMan->injectMouseDown(arg, id);
    return true;
}

bool BaseApplication::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    if (mTrayMgr->injectMouseUp(arg, id)) return true;
    mCameraMan->injectMouseUp(arg, id);
    return true;
}

//Adjust mouse clipping area
void BaseApplication::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);

    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}

//Unattach OIS before window shutdown (very important under Linux)
void BaseApplication::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if( rw == mWindow )
    {
        if( mInputManager )
        {
            mInputManager->destroyInputObject( mMouse );
            mInputManager->destroyInputObject( mKeyboard );

            OIS::InputManager::destroyInputSystem(mInputManager);
            mInputManager = 0;
        }
    }
}
