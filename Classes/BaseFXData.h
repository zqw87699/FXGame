//
//  BaseFXData.hpp
//  FairyKingdom
//
//  Created by 张大宗 on 16/11/8.
//
//

#ifndef __BASE_FX_DATA_H__
#define __BASE_FX_DATA_H__

#define FX_CREATE_DATA(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
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

#define FX_CREATE_DATA_WITH_IMAGE_AND_POSITION(__TYPE__) \
static __TYPE__* create(const std::string&img,const int fxpositoinX,const int fxpositionY) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
    { \
        pRet->initWithImageAndPosition(img,fxpositoinX,fxpositionY); \
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
class BaseFXData:public Ref,public BaseFxExtension{
public:
    virtual void initFX();
    virtual BaseFXData* copy();
    void initWithImageAndPosition(const std::string&img,const int fxpositoinX,const int fxpositionY);
    void setFXPosition(const int fxpositionX,const int fxpositionY);
    void setFXPosition(const Vec2&position);
    Vec2 getFXPosition();
    int getFXPositionX();
    int getFXPositionY();
    virtual void observeFX(const std::string &varName);
    FX_PROPERTY(std::string, fxImgFile,FxImgFile,"");
    FX_PROPERTY(int, fxTag,FxTag,-1);
    FX_CREATE_DATA(BaseFXData);
    FX_CREATE_DATA_WITH_IMAGE_AND_POSITION(BaseFXData);
private:
    int fxPositionX=-1;
    int fxPositionY=-1;
};

#endif /* __BASE_FX_DATA_H__ */
