#ifndef __FRAME_LISTENER_H__
#define __FRAME_LISTENER_H__

#include "ExampleFrameListener.h"

class MyFrameListener : public ExampleFrameListener
{
public:
  MyFrameListener(RenderWindow* win, Camera* cam, SceneManager *sceneMgr, bool bufferedKeys = false, bool bufferedMouse = false, bool bufferedJoy = false );
  virtual bool frameRenderingQueued(const FrameEvent& evt);
 
private:
  Ogre::SceneManager *mSceneMgr;
 
  bool mToucheAppuyee;
 
  Ogre::Real mMouvement;
  Ogre::Real mVitesse;
  Ogre::Real mVitesseRotation;
 
  Ogre::Radian mRotationX;
  Ogre::Radian mRotationY;
};

#endif
