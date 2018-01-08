//
//  BaseFXLayerView.hpp
//  GodWar
//
//  Created by 张大宗 on 16/10/29.
//
//

#ifndef __BASE_FX_LAYER_VIEW_H__
#define __BASE_FX_LAYER_VIEW_H__

#define FX_CREATE_LAYER(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        pRet->initFX(); \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        CC_SAFE_DELETE(pRet); \
        return nullptr; \
    } \
}

#define FX_CREATE_LAYER_WITH_RECT(__TYPE__) \
static __TYPE__* create(const Rect& rect) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        pRet->initFXWithRect(rect); \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        CC_SAFE_DELETE(pRet); \
        return nullptr; \
    } \
}

#define FX_CREATE_LAYER_WITH_PIC(__TYPE__) \
static __TYPE__* create(const std::string& filename) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        pRet->initFX(); \
        pRet->addBackgroundPic(filename); \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        CC_SAFE_DELETE(pRet); \
        return nullptr; \
    } \
}
#define FX_CREATE_LAYER_WITH_PIC_AND_RECT(__TYPE__) \
static __TYPE__* create(const std::string& filename,const Rect& rect) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
        pRet->initFXWithRect(rect); \
        pRet->addBackgroundPic(filename); \
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
USING_NS_CC;
class BaseFXLayerView:public Layer,public BaseFxExtension{
public:
    virtual void initFX();
    virtual void initListener();
    virtual void initFXWithRect(const Rect& rect);
    virtual void addBackgroundPic(const std::string& filename);
    virtual void observeFX(const std::string &varName);
    void setActualSize(float x, float y);
    FX_CREATE_LAYER(BaseFXLayerView);
    FX_CREATE_LAYER_WITH_PIC(BaseFXLayerView);
    FX_CREATE_LAYER_WITH_RECT(BaseFXLayerView);
    FX_CREATE_LAYER_WITH_PIC_AND_RECT(BaseFXLayerView);
};

#endif /* __BASE_FX_LAYER_VIEW_H__ */
