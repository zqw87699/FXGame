//
//  BaseFXMenu.hpp
//  RoyalArt
//
//  Created by 张大宗 on 2017/5/11.
//
//

#ifndef __BASE_FX_MENU_H__
#define __BASE_FX_MENU_H__

#include "cocos2d.h"
#include "BaseFXMenuItemView.h"

USING_NS_CC;

class BaseFXMenu:public Menu{
public:
    static BaseFXMenu* create();
    
    static BaseFXMenu* create(MenuItem* item, ...) CC_REQUIRES_NULL_TERMINATION;
    
    static BaseFXMenu* createWithArray(const Vector<MenuItem*>& arrayOfItems);
    
    static BaseFXMenu* createWithItem(MenuItem* item);

    static BaseFXMenu* createWithItems(MenuItem *firstItem, va_list args);
    
    MenuItem* getItemForTouch(Touch * touch, const Camera *camera);
};

#endif /* __BASE_FX_MENU_H__ */
