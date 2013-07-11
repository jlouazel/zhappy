/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
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

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "TutorialApplication.h"
#include "MyFrameListener.h"
#include "Graphic.hh"
#include "Treatment.hh"

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS || OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#   include <macUtils.h>
#   include <stdlib.h>
#   include <iostream>
#   include "AppDelegate.h"

#endif

GraphicClient *client;

TutorialApplication::TutorialApplication(void)
{
  mTimer = OGRE_NEW Ogre::Timer();
  mTimer->reset();
  this->mSceneMgr = OGRE_NEW Ogre::DefaultSceneManager("MainSceneMgr");
}

TutorialApplication::~TutorialApplication(void)
{
}

static std::string toString(int number)
{
  std::stringstream ss;

  ss << number;
  return ss.str();
}

void TutorialApplication::createScene(void)
{
  Ogre::Light* light = mSceneMgr->createLight("MainLight");
  light->setPosition(0.0f, 2000.0f, 0.0f);
  light->setCastShadows(true);
  Ogre::Light* light2 = mSceneMgr->createLight("MainLight2");
  light2->setPosition(0.0f, -2000.0f, 0.0f);
  light2->setCastShadows(true);
  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.8f, 0.8f, 0.8f));

  Ogre::Entity* planet = mSceneMgr->createEntity("Planet", "Donut.mesh");

  Ogre::SceneNode* planetNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("planetNode");
  planetNode->attachObject(planet);

  while (!client->isReady())
    parseRead(client, client->readOnServer());
}

static
bool    parseArgs(int ac, char **av, GraphicClient *client) {
  char  flag;

  while ((flag = getopt(ac, av, "p:h:")) > 0) {
    switch (flag) {
    case 'p':
      client->setPort(atoi(optarg));
      break;
    case 'h':
      client->setHost(optarg);
      break;
    case '?':
      return false;
    default:
      break;
    }
  }
  return true;
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
      client = new GraphicClient;
      if (parseArgs(argc, argv, client) == false)
	return (-1);
      client->setSocket(new_socket(client->getPort(), client->getHost().c_str(), SOCK_CLIENT));
      if (!client->getSocket())
	return (-1);
      if (client->readOnServer() == "BIENVENUE")
	client->writeOnServer("GRAPHIC\n");
      std::cout << "Listening on " << client->getHost() << ":" << client->getPort() << "..." << std::endl;
#if defined(OGRE_IS_IOS)
      NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
      int retVal = UIApplicationMain(argc, argv, @"UIApplication", @"AppDelegate");
      [pool release];
      return retVal;
#elif (OGRE_PLATFORM == OGRE_PLATFORM_APPLE) && __LP64__
      NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

        mAppDelegate = [[AppDelegate alloc] init];
        [[NSApplication sharedApplication] setDelegate:mAppDelegate];
        int retVal = NSApplicationMain(argc, (const char **) argv);
        
        [pool release];
        
        return retVal;
#else
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
	      e.getFullDescription().c_str() << std::endl;
#endif
        }
#endif
        return 0;
    }

#ifdef __cplusplus
}
#endif
