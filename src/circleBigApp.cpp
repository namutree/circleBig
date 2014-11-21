#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIO.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"
#include "PopcircleCon.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class circleBigApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();

    
    PopcircleCon popCirclepop;
    bool circleBool;
    int CircleOSC[2];
    float circleLifeSpan01, circleLifeSpan02;
    int amt;
};

void circleBigApp::prepareSettings(Settings *settings)
{
    settings->setWindowSize( 3840, 1080 );
    settings->setFrameRate( 60.0f );
}

void circleBigApp::setup()
{
    popCirclepop.setup();
    circleBool= false;
    Rand::randomize();

}

void circleBigApp::mouseMove( MouseEvent event )
{
    
    //event.getY()에다가 OSC신호 넣고
    //300을 원하는 threshold로 설정하삼
    CircleOSC[0] = CircleOSC[1];
    CircleOSC[1] = event.getY();
    if(CircleOSC[0]>300 && CircleOSC[1] <= 300){
        circleBool= true;
        circleLifeSpan01 = getElapsedSeconds()*100;
    }

}

void circleBigApp::update()
{
    popCirclepop.update();
    if(circleBool){
        amt = randInt(1,4);
        circleLifeSpan02 = getElapsedSeconds()*100;
        float circleInterval = circleLifeSpan02- circleLifeSpan01;
        if((int)circleInterval%95 <0.5){
            for(int i=0; i<amt; i++){
            popCirclepop.addPopCircle();
            }
        }
    }
    popCirclepop.removePopCircle();
}

void circleBigApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::enableAlphaBlending(true);
    gl::enableAdditiveBlending();
    popCirclepop.draw();
}

CINDER_APP_NATIVE( circleBigApp, RendererGl )
