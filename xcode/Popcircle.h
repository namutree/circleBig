//
//  Popcircle.h
//  circleBig
//
//  Created by john namu choi on 11/19/14.
//
//

#ifndef __circleBig__Popcircle__
#define __circleBig__Popcircle__

#include <stdio.h>
#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

#include <vector>

class Popcircle {
public:
    Popcircle();
    Popcircle(const ci::gl::TextureRef &img00, ci::Vec2f Cpos, cinder::Color ccc);
    void setup();
    void update();
    void draw();


    float aa;
    float oppa;
    float lifeSpanTemp, lifeSpan, lifeLimit;
    ci::Vec2f Crandom;
    ci::Vec2f Cpos;
    cinder::Color circleColor;
    
    
    cinder::gl::TextureRef CircleImg;
};


#endif /* defined(__circleBig__Popcircle__) */
