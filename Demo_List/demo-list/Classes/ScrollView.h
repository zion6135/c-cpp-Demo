#ifndef __SCROLLVIEW_h__
#define __SCROLLVIEW_h__

#include "cocos2d.h"
#include "../extensions/cocos-ext.h"
 
USING_NS_CC;
USING_NS_CC_EXT;

class _Scroll : public cocos2d::Scene,public ScrollViewDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();    
    CREATE_FUNC(_Scroll);


	//scroll 委托
	void scrollViewDidScroll(cocos2d::extensions::ScrollView* view);
	//void scrollViewDidZoom(ScrollView* view);
	// void scrollViewMoveOver(ScrollView* view);

private:
	Vector<Sprite*> sp_vec;//声明一个容器
};
#endif