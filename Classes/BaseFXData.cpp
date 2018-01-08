//
//  BaseFXData.cpp
//  FairyKingdom
//
//  Created by 张大宗 on 16/11/8.
//
//

#include "BaseFXData.h"

void BaseFXData::initFX(){
    
}

BaseFXData* BaseFXData::copy(){
    auto data = BaseFXData::create(this->fxImgFile, fxPositionX, fxPositionY);
    data->setFxTag(this->fxTag);
    return data;
}

void BaseFXData::setFXPosition(const cocos2d::Vec2 &position){
    this->fxPositionX = position.x;
    this->fxPositionY = position.y;
}

void BaseFXData::setFXPosition(const int fxpositionX, const int fxpositionY){
    this->fxPositionX=fxpositionX;
    this->fxPositionY=fxpositionY;
}
void BaseFXData::initWithImageAndPosition(const std::string &img, const int fxpositoinX, const int fxpositionY){
    this->initFX();
    this->fxImgFile=img;
    this->setFXPosition(fxpositoinX, fxpositionY);
}
void BaseFXData::observeFX(const std::string &varName){
    
}
Vec2 BaseFXData::getFXPosition(){
    return Vec2(fxPositionX, fxPositionY);
}
int BaseFXData::getFXPositionX(){
    return fxPositionX;
}
int BaseFXData::getFXPositionY(){
    return fxPositionY;
}
