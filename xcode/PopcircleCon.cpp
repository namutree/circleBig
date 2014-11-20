//
//  PopcircleCon.cpp
//  circleBig
//
//  Created by john namu choi on 11/20/14.
//
//

#include "PopcircleCon.h"
#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using std::list;

PopcircleCon::PopcircleCon(){}


void PopcircleCon::setup()
{
    if( ! img00 )
        img00 = gl::Texture::create( ci::loadImage( ci::app::loadResource( "BigCircle.png" ) ) );
 
}

void PopcircleCon::update()
{
    for( list<Popcircle>::iterator p = mPopcircle.begin(); p != mPopcircle.end(); ++p ){
        p->update();
    }
}

void PopcircleCon::draw()
{
    for( list<Popcircle>::iterator p = mPopcircle.begin(); p != mPopcircle.end(); ++p ){
        p->draw();
    }
}

void PopcircleCon::addPopCircle()
{
    colorChoice = Rand::randFloat(1.f);
    if      (colorChoice<0.25) circleCr = cinder::Color(1,0.95,1);
    else if (colorChoice<0.50) circleCr = cinder::Color(1,1,0.5);
    else if (colorChoice<0.75) circleCr = cinder::Color(0.5,1,1);
    else                       circleCr = cinder::Color(1,0.7,0.17);
    
    float posX = Rand::randFloat(getWindowHeight()/3,getWindowWidth()-getWindowHeight()/3);
    float posY = Rand::randFloat(getWindowHeight()/3,getWindowHeight()-getWindowHeight()/3);
    
    Cpos = Vec2f(posX, posY);
    mPopcircle.push_back(Popcircle(img00, Cpos,circleCr));

}

void PopcircleCon::removePopCircle()
{
    for( list<Popcircle>::iterator p = mPopcircle.begin(); p != mPopcircle.end(); ++p ){
        if(p->lifeSpan>p->lifeLimit){
            p=mPopcircle.erase(p);
        }
    }
}