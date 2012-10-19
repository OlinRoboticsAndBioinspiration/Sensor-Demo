#include "DemoApplication.h"
#include <fstream>
#include <string>

DemoApplication::DemoApplication(void)
{
  rot_x = 0;
  rot_y = 0;
  rot_z = 0;
  resetOrientation();
}

DemoApplication::~DemoApplication(void)
{
}

bool DemoApplication::keyPressed( const OIS::KeyEvent &arg )
{
  if (arg.key == OIS::KC_SPACE)
  {
    resetOrientation();
  }
  return BaseApplication::keyPressed(arg);
}

void DemoApplication::createScene(void)
{
   // Set the scene's ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));

    // Create an Entity
    Ogre::Entity* bodyEntity = mSceneMgr->createEntity("Head", "robot.mesh");


    // Create a SceneNode and attach the Entity to it
    bodyNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("HeadNode");
    bodyNode->attachObject(bodyEntity);

    // Create a Light and set its position
    Ogre::Light* light = mSceneMgr->createLight("MainLight");
    light->setPosition(20.0f, 80.0f, 50.0f);
    // create your scene here :)
}

bool DemoApplication::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
  std::ifstream ifs("sensors.txt");
  std::string contents;
  contents.assign(std::istreambuf_iterator<char>(ifs),
                       std::istreambuf_iterator<char>()  );
  if (contents.size() >= 20) {
    bodyNode->resetOrientation();
    float x, y, z;
    sscanf(contents.c_str(), "%f, %f, %f", &x, &y, &z);
    Ogre::Radian xr = Ogre::Radian(x - rot_x_orig);
    Ogre::Radian yr = Ogre::Radian(y - rot_y_orig);
    Ogre::Radian zr = Ogre::Radian(z - rot_z_orig);

    rot_x = x;
    rot_y = y;
    rot_z = z;

    bodyNode->yaw(xr/4);
    bodyNode->pitch(yr/4); //top down rotaiton
    bodyNode->roll(zr/4);
  }
  return BaseApplication::frameRenderingQueued(evt);
}

void DemoApplication::resetOrientation()
{
  rot_x_orig = rot_x;
  rot_y_orig = rot_y;
  rot_z_orig = rot_z;
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
        // Create application object
        DemoApplication app;

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

        return 0;
    }

#ifdef __cplusplus
}
#endif
