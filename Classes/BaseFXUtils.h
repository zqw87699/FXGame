//
//  BaseFXUtils.hpp
//  GodWar
//
//  Created by 张大宗 on 16/10/28.
//
//

#ifndef __BASE_FX_UTILS_H__
#define __BASE_FX_UTILS_H__

#include "cocos2d.h"

#define isSourceTypeOGWlass(type,source)  dynamic_cast<type*>(source)?true:false


USING_NS_CC;
class BaseFXUtils{
public:
    template<class T,class B>
    static void pushBackVector(Vector<T>& target,const Vector<B> base){
        for (int i=0; i<base.size(); i++) {
            target.pushBack((T)base.at(i));
        }
    };
    template<class T,class B>
    static void pushBack(Vector<T>&target,int count,B base,...){
        int j = 0;
        va_list args;    //第1步,定义这个指向参数列表的变量
        va_start(args, base);//第2步,把上面这个变量初始化.即让它指向参数列表
        target.pushBack(base);
        while( j < count - 1 )
        {
            B nowBase=va_arg(args, B);
            target.pushBack(nowBase);
            j+=1;
        }
        va_end(args);    //第4步,做一些清理工作
    }
    static int randomMethod(int Num){
        if (Num == 0) {
            return 0;
        }
        return rand()%Num;
    }
    
    static void initRandSeed(){
        //获取系统时间
        struct timeval now;
        gettimeofday(&now, NULL);
        //初始化随机种子
        //timeval是个结构体，里边有俩个变量，一个是以秒为单位的，一个是以微妙为单位的
        unsigned rand_seed = (unsigned)(now.tv_sec+now.tv_usec);
        srand(rand_seed);
    }
    
    static Vec2 getWorldPosition(Node*source){
        if (source->getParent()) {
            return source->getParent()->convertToWorldSpace(source->getPosition());
        }else{
            return source->getPosition();
        }
    }
    
    static Vec2 getNodePosition(Node*node,Node*source){
        Vec2 position = BaseFXUtils::getWorldPosition(source);
        return node->convertToNodeSpace(position);
    }

    static std::string createKey(const std::string &key,int d){
        __String *Ss = __String::createWithFormat("%s%d",key.c_str(),d);
        return Ss->_string;
    }
};

#endif /* __BASE_FX_UTILS_H__ */
