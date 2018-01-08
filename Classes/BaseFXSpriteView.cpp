//
//  BaseFXSpriteView.cpp
//  GodWar
//
//  Created by 张大宗 on 16/10/27.
//
//

#include "BaseFXSpriteView.h"

void BaseFXSpriteView::initFX(){
    this->setCascadeColorEnabled(true);
    this->setCascadeOpacityEnabled(true);
}
void BaseFXSpriteView::setActualSize(float x, float y){
    this->actualSize = Vec2(x, y);
    this->setScale(x/this->getContentSize().width, y/this->getContentSize().height);
    this->setScaleXRate(x/this->getContentSize().width);
    this->setScaleYRate(y/this->getContentSize().height);
}
void BaseFXSpriteView::observeFX(const std::string &varName){
    
}

Vec2 BaseFXSpriteView::getActualSize(){
    return actualSize;
}
