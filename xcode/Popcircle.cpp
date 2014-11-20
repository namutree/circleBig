//
//  Popcircle.cpp
//  circleBig
//
//  Created by john namu choi on 11/19/14.
//
//

#include "Popcircle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "cinder/app/AppNative.h"

using namespace ci;
using namespace ci::app;
using namespace std;


Popcircle::Popcircle(){}
Popcircle::Popcircle(const ci::gl::TextureRef &img00, Vec2f Circlepos, cinder::Color ccc): CircleImg (img00)
{
    Cpos = Circlepos;
    //using seconds*10 for natural opacity
    lifeSpanTemp= getElapsedSeconds()*10;
    // set as 5 sec.
    lifeLimit =50;
    circleColor = ccc;
}
void Popcircle::setup()
{
}

void Popcircle::update()
{
    //erase after 5.0 sec. -> using 50
    lifeSpan = getElapsedSeconds()*10 - lifeSpanTemp;
    aa      = Rand::randFloat(10,getWindowHeight()/3);
    
    // big circle -> transparent, small circle ->vivid
    oppa    = ci::lmap(aa, 10.f, (float)getWindowHeight()/3, 1.f, 0.2f);
    // when lifespan goes up, oppa decreases.
    oppa = oppa /lifeLimit *(lifeLimit-lifeSpan);

    Crandom = Vec2f(aa, aa );

}

void Popcircle::draw()
{

    gl::color(circleColor.r,circleColor.g, circleColor.b, oppa);
    gl::draw( CircleImg, Rectf(Cpos-Crandom,Cpos+Crandom));

}