//
//  BaseFXMenuItemView.hpp
//  GodWar
//
//  Created by 张大宗 on 16/10/27.
//
//

#ifndef __BASE_FX_MENUITEM_VIEW_H__
#define __BASE_FX_MENUITEM_VIEW_H__

#define FX_CREATE_MENUITEM(__TYPE__) \
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

#define FX_CREATE_MENUITEM_WITH_IMAGE(__TYPE__) \
static __TYPE__* create(const std::string& normalImage, const std::string& selectedImage) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->initWithNormalImage(normalImage, selectedImage,"", (const ccMenuCallback&)nullptr)) \
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

#define FX_CREATE_MENUITEM_WITH_IMAGE_AND_CALLBACK(__TYPE__) \
static __TYPE__* create(const std::string& normalImage, const std::string& selectedImage,const ccMenuCallback& callback) \
{ \
__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->initWithNormalImage(normalImage, selectedImage,"", callback)) \
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

#define  FX_CREATE_MENUITEM_WITH_DISABLE_IMAGE_AND_CALLBACK(__TYPE__)\
static __TYPE__* create(const std::string& normalImage, const std::string& selectedImage,const std::string& disableImage,const ccMenuCallback& callback)\
{\
__TYPE__ *pRet = new(std::nothrow) __TYPE__();\
    if (pRet && pRet->initWithNormalImage(normalImage, selectedImage,disableImage, callback)) \
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
USING_NS_CC;

class BaseFXMenuItemView:public MenuItemImage,public BaseFxExtension{
public:
    virtual void initFX();
    virtual void observeFX(const std::string &varName);
    FX_CREATE_MENUITEM(BaseFXMenuItemView);
    FX_CREATE_MENUITEM_WITH_IMAGE(BaseFXMenuItemView);
    FX_CREATE_MENUITEM_WITH_IMAGE_AND_CALLBACK(BaseFXMenuItemView);
    FX_CREATE_MENUITEM_WITH_DISABLE_IMAGE_AND_CALLBACK(BaseFXMenuItemView);
public:
    void setActualSize(float x, float y);
    void setFlippedX(bool flippedX);
};


#endif /* __BASE_FX_MENUITEM_VIEW_H__ */
