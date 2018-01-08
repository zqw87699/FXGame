//
//  BaseFXMenuItemView.cpp
//  GodWar
//
//  Created by 张大宗 on 16/10/27.
//
//

#include "BaseFXMenuItemView.h"

void BaseFXMenuItemView::initFX(){
    
}
void BaseFXMenuItemView::setActualSize(float x, float y){
    this->setScale(x/this->getContentSize().width, y/this->getContentSize().height);
}
void BaseFXMenuItemView::observeFX(const std::string &varName){
    
}
void BaseFXMenuItemView::setFlippedX(bool flippedX){
    if (this->getNormalImage()!=nullptr) {
        ((Sprite*)this->getNormalImage())->setFlippedX(flippedX);
    }
    if (this->getSelectedImage()!=nullptr) {
        ((Sprite*)this->getSelectedImage())->setFlippedX(flippedX);
    }
    if (this->getDisabledImage()!=nullptr) {
        ((Sprite*)this->getDisabledImage())->setFlippedX(flippedX);
    }
}
