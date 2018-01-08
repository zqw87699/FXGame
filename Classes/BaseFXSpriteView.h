//
//  BaseFXSpriteView.hpp
//  GodWar
//
//  Created by 张大宗 on 16/10/27.
//
//

#ifndef __BASE_FX_SPRITE_VIEW_H__
#define __BASE_FX_SPRITE_VIEW_H__

#define FX_CREATE_SPRITE(__TYPE__) \
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

#define FX_CREATE_SPRITE_WITH_IMAGE(__TYPE__) \
static __TYPE__* create(const std::string& image) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->initWithFile(image)) \
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

#include "cocos2d.h"
#include "BaseFxExtension.h"
#include "BaseFXData.h"

USING_NS_CC;
class BaseFXSpriteView:public Sprite,public BaseFxExtension{
public:
    virtual void initFX();
    void setActualSize(float x, float y);
    Vec2 getActualSize();
    virtual void observeFX(const std::string &varName);
    FX_CREATE_SPRITE(BaseFXSpriteView);
    FX_CREATE_SPRITE_WITH_IMAGE(BaseFXSpriteView);
public:
    FX_PROPERTY(float, scaleXRate, ScaleXRate, 1.0f);
    FX_PROPERTY(float, scaleYRate, ScaleYRate, 1.0f);
    FX_ABSTRACT_PROPERTY(BaseFXData, fxData, FXData, nullptr);
    Vec2 actualSize;
};

#endif /* __BASE_FX_SPRITE_VIEW_H__ */
