#ifndef __DemoApplication_h_
#define __DemoApplication_h_

#include "BaseApplication.h"

class DemoApplication : public BaseApplication
{
public:
    Ogre::SceneNode* bodyNode;
    DemoApplication(void);
    virtual ~DemoApplication(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
protected:
    virtual void createScene(void);

    virtual void resetOrientation();
    float rot_x;
    float rot_y;
    float rot_z;

    float rot_x_orig;
    float rot_y_orig;
    float rot_z_orig;

    bool oldIssued = false;
    int motorSpeed = 0;
};

#endif // #ifndef __DemoApplication_h_
