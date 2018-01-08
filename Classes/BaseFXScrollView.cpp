//
//  BaseFXScrollView.cpp
//  GodWar
//
//  Created by 张大宗 on 16/12/20.
//
//

#include "BaseFXScrollView.h"

void BaseFXScrollView::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    if (!this->isVisible())
    {
        return;
    }
    
    auto touchIter = std::find(_touches.begin(), _touches.end(), touch);
    
    if (touchIter != _touches.end())
    {
        if (_touches.size() == 1 && _touchMoved)
        {
            BaseFXScrollViewDelegate*fxdelegate=(BaseFXScrollViewDelegate*)this->getDelegate();
            fxdelegate->scrollViewDidEndDecelerating(this);
        }
        _touches.erase(touchIter);
    }
    
    if (_touches.size() == 0)
    {
        _dragging = false;
        _touchMoved = false;
    }
}

void BaseFXScrollView::initFX(){
    
}
