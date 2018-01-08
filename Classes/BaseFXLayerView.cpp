//
//  BaseFXLayerView.cpp
//  GodWar
//
//  Created by 张大宗 on 16/10/29.
//
//

#include "BaseFXLayerView.h"
#include "BaseFXSpriteView.h"
void BaseFXLayerView::initFXWithRect(const cocos2d::Rect &rect)
{
    this->setContentSize(Size(rect.size.width,rect.size.height));
    this->setIgnoreAnchorPointForPosition(false);
    this->setPosition(Vec2(rect.origin.x+rect.size.width/2.0,rect.origin.y+rect.size.height/2.0));
    this->initFX();
}

void BaseFXLayerView::setActualSize(float x, float y){
    this->setScale(x/this->getContentSize().width, y/this->getContentSize().height);
}

void BaseFXLayerView::initFX()
{
    this->initListener();
}

void BaseFXLayerView::initListener(){
    
}

void BaseFXLayerView::addBackgroundPic(const std::string &filename){
    auto sprite=BaseFXSpriteView::create(filename);
    sprite->setActualSize(this->getContentSize().width, this->getContentSize().height);
    sprite->setPosition(this->getContentSize().width/2.0,this->getContentSize().height/2.0);
    this->addChild(sprite,0);
}
void BaseFXLayerView::observeFX(const std::string &varName){
    
}
