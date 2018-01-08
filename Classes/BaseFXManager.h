//
//  BaseFXManager.hpp
//  FairyKingdom
//
//  Created by 张大宗 on 16/11/7.
//
//

#ifndef __BASE_FX_VIEWMODEL_H__
#define __BASE_FX_VIEWMODEL_H__

#define FX_CREATE_MANAGER(__TYPE__) \
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

#include "cocos2d.h"
#include "BaseFxExtension.h"
#include "BaseFXData.h"

USING_NS_CC;
class BaseFXManager:public Node,public BaseFxExtension{
public:
    virtual void initFX();
    virtual void onExit();
    virtual void onEnter();
    virtual void observeFX(const std::string &varName);
    FX_CREATE_MANAGER(BaseFXManager);
public:
    /*
     * 移除子元素
     */
    void removeAllData();
    /*
     * 添加子元素
     */
    void addData(BaseFXData*data);
private:
    /*
     * 子元素列表
     */
    Vector<Ref*>childrenData;

};

#endif /* __BASE_FX_VIEWMODEL_H__ */
