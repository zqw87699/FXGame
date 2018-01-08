//
//  BaseFXScrollLayerView.cpp
//  GodWar
//
//  Created by 张大宗 on 2017/1/6.
//
//

#include "BaseFXScrollLayerView.h"

void BaseFXScrollLayerView::initFX(){
    scrollLayer=BaseFXLayerView::create(Rect(0, 0, this->getContentSize().width,this->getContentSize().height));
    scrollLayer->setAnchorPoint(Vec2::ZERO);
    scrollLayer->setPosition(Vec2::ZERO);
    
    scrollView = BaseFXScrollView::create(Size(this->getContentSize().width,this->getContentSize().height),scrollLayer);//创建一个scrollView
    scrollView->setAnchorPoint(Vec2::ZERO);
    scrollView->setPosition(Vec2::ZERO);
    this->addChild(scrollView);
    
    scrollView->setContentOffset(Vec2::ZERO);
    scrollView->setContentSize(Size(this->getContentSize().width,this->getContentSize().height));//设置scrollview区域的大小
    scrollView->setDirection(extension::ScrollView::Direction::HORIZONTAL);
    scrollView->setBounceable(true);//设置CCScrollView有弹性效果
    //    务必在AppDelegate.cpp 中开启ios多点触莫的支持
    scrollView->setTouchEnabled(true);//开启监听多触点
    scrollView->setDelegate(this);//注册监听
}

void BaseFXScrollLayerView::scrollViewDidScroll(extension::ScrollView *view){
    CCLOG("%f",view->getContentOffset().x);
}

void BaseFXScrollLayerView::scrollViewDidEndDecelerating(BaseFXScrollView *view){
    if (fabs(view->getContentOffset().x+this->currentPage*this->getContentSize().width)>0.2*this->getContentSize().width) {
        if (view->getContentOffset().x<-this->currentPage*this->getContentSize().width) {
            this->currentPage+=1;
        }else{
            this->currentPage-=1;
        }
        if (this->currentPage>=totalPage) {
            this->currentPage=totalPage;
        }else if (this->currentPage<=0){
            this->currentPage=0;
        }
    }
    
    view->setContentOffsetInDuration(Vec2(-this->currentPage*this->getContentSize().width, 0), 0.2f);
}
void BaseFXScrollLayerView::addSubView(cocos2d::Node *pView){
    scrollLayer->addChild(pView);
}
void BaseFXScrollLayerView::removeAllSubViews(){
    scrollLayer->removeAllChildren();
}
void BaseFXScrollLayerView::setScrollContentSize(const Size &pSize){
    scrollLayer->setContentSize(pSize);
    scrollView->setContentSize(pSize);
}
void BaseFXScrollLayerView::setScrollContentOffset(const Vec2 &pOff){
    scrollView->setContentOffset(pOff);
}
