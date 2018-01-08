//
//  BaseFXSingleton.hpp
//  GodWar
//
//  Created by 张大宗 on 2017/1/6.
//
//

#ifndef __BASE_FX_SINGLETON_H__
#define __BASE_FX_SINGLETON_H__

#define FX_SINGLETON(__TYPE__)\
static __TYPE__*  __TYPE___singleton;

#define FX_CREATE_SINGLETON(__TYPE__) \
public:static __TYPE__* getInstance() \
{ \
    if(!__TYPE___singleton){\
        __TYPE___singleton = new(std::nothrow) __TYPE__(); \
        __TYPE___singleton->initFX();\
    }\
    return (__TYPE__*)__TYPE___singleton;\
}\



#include "cocos2d.h"
USING_NS_CC;

class BaseFXSingleton;
FX_SINGLETON(BaseFXSingleton);

class BaseFXSingleton:public Ref{
public:
    virtual void initFX();
    FX_CREATE_SINGLETON(BaseFXSingleton);
};

#endif /* __BASE_FX_SINGLETON_H__ */
