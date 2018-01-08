//
//  BaseFxExtension.hpp
//  FairyKingdom
//
//  Created by 张大宗 on 16/11/16.
//
//

#ifndef __BASE_FX_EXTENSION_H__
#define __BASE_FX_EXTENSION_H__

#define FX_CREATE_OBJECT(__TYPE__) \
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

#define FX_PROPERTY_OBSERVER(varType, varName,funcName, defaultValue)\
private:varType varName=defaultValue;\
public: virtual const varType& get##funcName(void) const { \
            return varName; \
        }\
public: virtual void set##funcName(const varType& var){ \
            varName = var; \
            observeFX(#varName); \
        }\

#define FX_PROPERTY(varType, varName,funcName, defaultValue)\
private:varType varName=defaultValue;\
public: virtual const varType& get##funcName(void) const { \
            return varName; \
        }\
public: virtual void set##funcName(const varType& var){ \
            varName = var; \
        }\

#define FX_ABSTRACT_PROPERTY(varType,varName,funcName,defaultValue)\
private:varType*varName;\
public: virtual varType*get##funcName(){\
            return varName;\
        }\
public: virtual void set##funcName(varType*var){\
            varName=var;\
        }\

#define FX_ABSTRACT_PROPERTY_OBSERVE(varType,varName,funcName,defaultValue)\
private:varType*varName;\
public: virtual varType*get##funcName(){\
            return varName;\
        }\
public: virtual void set##funcName(varType*var){\
            varName=var;\
            observeFX(#varName); \
        }\


#include <stdio.h>

class BaseFxExtension{
    virtual void observeFX(const std::string &varName);
};

#endif /* __BASE_FX_EXTENSION_H__ */
