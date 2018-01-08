//
//  BaseFXViewController.cpp
//  GodWar
//
//  Created by 张大宗 on 16/10/27.
//
//

#include "BaseFXViewController.h"

void BaseFXViewController::initMap(int choseMap){
    this->choseMap = choseMap;
}

void BaseFXViewController::initFX(){
    this->initFXManager();
}
void BaseFXViewController::onEnter(){
    Scene::onEnter();
}
void BaseFXViewController::initFXManager(){
    
}
void BaseFXViewController::observeFX(const std::string &varName){
    
}
void BaseFXViewController::addManager(BaseFXManager *manager){
    this->addChild(manager);
    managerList.pushBack(manager);
}
void BaseFXViewController::onExit(){
    Scene::onExit();
    managerList.clear();
}
