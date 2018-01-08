//
//  BaseFXManager.cpp
//  FairyKingdom
//
//  Created by 张大宗 on 16/11/7.
//
//

#include "BaseFXManager.h"

void BaseFXManager::addData(BaseFXData *data){
    this->childrenData.pushBack(data);
}

void BaseFXManager::removeAllData(){
    this->childrenData.clear();
}

void BaseFXManager::initFX(){
    
}

void BaseFXManager::onEnter(){
    Node::onEnter();
}

void BaseFXManager::onExit(){
    Node::onExit();
    this->removeAllData();
}
void BaseFXManager::observeFX(const std::string &varName){
    
}
