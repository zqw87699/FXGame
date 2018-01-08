//
//  BaseFXScrollView.hpp
//  GodWar
//
//  Created by 张大宗 on 16/12/20.
//
//

#ifndef __BASE_FX_SCROLLVIEW_H__
#define __BASE_FX_SCROLLVIEW_H__

#define FX_CREATE_SCROLLVIEW_WITH_SIZE_AND_CONTAINER(__TYPE__) \
static __TYPE__* create(Size size, Node* container) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet&&pRet->initWithViewSize(size,container)) \
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

#define FX_CREATE_SCROLLVIEW(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet&&pRet->init()) \
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

#include "cocos-ext.h"
USING_NS_CC;
class BaseFXScrollView:public extension::ScrollView{
public:
    virtual void initFX();
    FX_CREATE_SCROLLVIEW(BaseFXScrollView);
    FX_CREATE_SCROLLVIEW_WITH_SIZE_AND_CONTAINER(BaseFXScrollView);
public:
    void onTouchEnded(Touch *touch, Event *event) override;
};

class BaseFXScrollViewDelegate:public extension::ScrollViewDelegate{
public:
    virtual void scrollViewDidEndDecelerating(BaseFXScrollView* view) {};
    virtual void scrollViewDidScroll(extension::ScrollView* view) {};
    virtual void scrollViewDidZoom(extension::ScrollView* view) {};
};

#endif /* __BASE_FX_SCROLLVIEW_H__ */
