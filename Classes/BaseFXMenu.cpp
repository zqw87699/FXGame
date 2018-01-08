//
//  BaseFXMenu.cpp
//  RoyalArt
//
//  Created by 张大宗 on 2017/5/11.
//
//

#include "BaseFXMenu.h"

BaseFXMenu* BaseFXMenu::create()
{
    return BaseFXMenu::create(nullptr, nullptr);
}


BaseFXMenu * BaseFXMenu::create(MenuItem* item, ...)
{
    va_list args;
    va_start(args,item);
    
    BaseFXMenu *ret = BaseFXMenu::createWithItems(item, args);
    
    va_end(args);
    
    return ret;
}

BaseFXMenu* BaseFXMenu::createWithArray(const Vector<MenuItem*>& arrayOfItems)
{
    auto ret = new (std::nothrow) BaseFXMenu();
    if (ret && ret->initWithArray(arrayOfItems))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    
    return ret;
}

BaseFXMenu* BaseFXMenu::createWithItems(MenuItem* item, va_list args)
{
    Vector<MenuItem*> items;
    if( item )
    {
        items.pushBack(item);
        MenuItem *i = va_arg(args, MenuItem*);
        while(i)
        {
            items.pushBack(i);
            i = va_arg(args, MenuItem*);
        }
    }
    
    return BaseFXMenu::createWithArray(items);
}

MenuItem* BaseFXMenu::getItemForTouch(cocos2d::Touch *touch, const cocos2d::Camera *camera){
    Vec2 touchLocation = touch->getLocation();
    Vector<Node*> clickChild = _children;
    clickChild.reverse();
    for (const auto &item: clickChild)
    {
        MenuItem* child = dynamic_cast<MenuItem*>(item);
        if (nullptr == child || false == child->isVisible() || false == child->isEnabled())
        {
            continue;
        }
        Rect rect;
        rect.size = child->getContentSize();
        if (isScreenPointInRect(touchLocation, camera, child->getWorldToNodeTransform(), rect, nullptr))
        {
            return child;
        }
    }
    return nullptr;
}
