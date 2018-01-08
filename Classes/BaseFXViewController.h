//
//  BaseFXViewController.hpp
//  GodWar
//
//  Created by 张大宗 on 16/10/27.
//
//

#ifndef __BASE_FX_VIEW_CONTROLLER_H__
#define __BASE_FX_VIEW_CONTROLLER_H__

#define FX_CREATE_CONTROLLER(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        pRet->initFX();\
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        CC_SAFE_DELETE(pRet); \
        return nullptr; \
    } \
}

#define FX_CREATE_CONTROLLER_WITH_MAP(__TYPE__) \
static __TYPE__* create(int choseMap) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        pRet->initMap(choseMap);\
        pRet->initFX();\
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        CC_SAFE_DELETE(pRet); \
        return nullptr; \
    } \
}

#include "cocos2d.h"
#include "BaseFxExtension.h"
#include "BaseFXManager.h"
USING_NS_CC;
class BaseFXViewController:public Scene,public BaseFxExtension{
public:
    virtual void initFX();
    virtual void initMap(int choseMap);
    virtual void onEnter();
    virtual void onExit();
    virtual void initFXManager();
    virtual void observeFX(const std::string &varName);
    FX_CREATE_CONTROLLER(BaseFXViewController);
protected:
    int choseMap;
public:
    /*
     * 添加管理器
     */
    void addManager(BaseFXManager*manager);
public:
    /*
     * 管理器列表
     */
    Vector<BaseFXManager*>managerList;
};

#endif /* __BASE_FX_VIEW_CONTROLLER_H__ */
