//
//  BaseFXScrollLayerView.hpp
//  GodWar
//
//  Created by 张大宗 on 2017/1/6.
//
//

#ifndef __BASE_FX_SCROLL_LAYER_VIEW_H__
#define __BASE_FX_SCROLL_LAYER_VIEW_H__

#include "BaseFXLayerView.h"
#include "BaseFXScrollView.h"
class BaseFXScrollLayerView:public BaseFXLayerView,public BaseFXScrollViewDelegate{
public:
    virtual void initFX();
    FX_CREATE_LAYER_WITH_RECT(BaseFXScrollLayerView);
    void addSubView(Node*pView);
    void removeAllSubViews();
    void setScrollContentSize(const Size&pSize);
    void setScrollContentOffset(const Vec2&pOff);
public:
    virtual void scrollViewDidEndDecelerating(BaseFXScrollView* view);
    virtual void scrollViewDidScroll(extension::ScrollView* view);
public:
    FX_PROPERTY(int, currentPage, CurrentPage, 0);
    FX_PROPERTY(int, totalPage, TotalPage, 0);
private:
    BaseFXLayerView*scrollLayer;
    BaseFXScrollView*scrollView;
};

#endif /* __BASE_FX_SCROLL_LAYER_VIEW_H__ */
