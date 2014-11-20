//
//  PopcircleCon.h
//  circleBig
//
//  Created by john namu choi on 11/20/14.
//
//

#ifndef __circleBig__PopcircleCon__
#define __circleBig__PopcircleCon__

#include <stdio.h>
#pragma once
#include "cinder/Rand.h"
#include "cinder/Channel.h"
#include "Popcircle.h"
#include <list>

class PopcircleCon {
public:
    PopcircleCon();
    void setup();
    void update();
    void draw();
    void addPopCircle();
    void removePopCircle();
    
    std::list<Popcircle> mPopcircle;
    cinder::Rand generator;
    
    ci::gl::TextureRef img00;
    ci::Vec2f Cpos;
    cinder::Color circleCr;
    float colorChoice;
    
    
};


#endif /* defined(__circleBig__PopcircleCon__) */
