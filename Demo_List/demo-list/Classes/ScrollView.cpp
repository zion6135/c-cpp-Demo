#include "ScrollView.h"

USING_NS_CC;

Scene* _Scroll::createScene()
{
    return _Scroll::create();
}

bool _Scroll::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
	auto picture_start_pos = Size(300,100); //根据不同的图片来调节

	auto scroll_layer = LayerColor::create(Color4B(255,255,255,255));//创建scrollView中的容器层
	scroll_layer->setAnchorPoint(Point::ZERO);
	scroll_layer->setPosition(Point::ZERO);
	scroll_layer->setContentSize(Size(960, 300));//1.设置容器层大小

	auto scrollView = ScrollView::create(Size(480,100),scroll_layer);//如果横向滑动：量程为480 纵向滑动量程为100
	scrollView->setDelegate(this);
	scrollView->setDirection(ScrollView::Direction::HORIZONTAL);//设置滚动方向为竖直  HORIZONTAL  VERTICAL
    scrollView->setContentOffset(picture_start_pos,1);  //设置Scrollview起点位置
	this->addChild(scrollView);

	auto boy = Sprite::create("HelloWorld.png");
	boy->setAnchorPoint(Point::ZERO);
    boy->setPosition(Point(0.0f,0.0f));//2.在容器中以左下角为参考点的位置
	scroll_layer->addChild(boy);

    sp_vec.pushBack(boy);

    return true;
}


void _Scroll::scrollViewDidScroll(ScrollView* view)
{

    //在scrollView拖动时响应该函数
    auto offsetPosX = (view->getContentOffset()).x ;
    auto offsetPosy = (view->getContentOffset()).y ;
    sp_vec.at(0)->setPosition(Point( offsetPosX, offsetPosy ));

    printf("x==== %f\n",offsetPosX);
    printf("y==== %f\n",offsetPosy);
	
    if( view->isDragging())
	{
		//CCLOG("ScrollView移动");
	}
}
/*
void _Scroll::scroll_picture(Layout* layout, string name)
{
    auto back_layer_size = Size(1920,2700);
    auto scroll_pos = Vec2(176,200);
    auto picture_start_pos = Size(0,-2200);
    
    if((scroll == NULL) || (parkSprite == NULL) || (scrollview == NULL)){
        scroll = new Layer();

        parkSprite = new Sprite();

        scrollview = new cocos2d::extension::ScrollView();
        scrollview->initWithViewSize(Size(1568,400), scroll);//可视区域大小
    }
    if((scroll != NULL) && (parkSprite != NULL) && (scrollview != NULL)){
        scroll->setContentSize(back_layer_size); //屏幕宽度
        scroll->setAnchorPoint(Vec2(0, 1));//左下角为参考点
        scroll->setPosition(Vec2(0,0));

        parkSprite->initWithFile(name);
        parkSprite->setAnchorPoint(Vec2(0, 0));//左下角为原点
        parkSprite->setPosition(Vec2(0,0)); //容器内的坐标
        scroll->addChild(parkSprite);

        scrollview->setAnchorPoint(Vec2(0, 0)); //左下角为原点
        scrollview->setPosition(scroll_pos);
        scrollview->setDirection(cocos2d::extension::ScrollView::Direction::VERTICAL);
        scrollview->setDelegate(this);
        layout->addChild(scrollview);
        scrollview->setContentOffset(picture_start_pos,1);  //设置Scrollview起点位置
    }
}

void _Scroll::scrollViewDidScroll(cocos2d::extension::ScrollView* view)  //滚动回调函数
{
    if(view == NULL){
        return;
    }
    auto offsetPosX = (view->getContentOffset()).x ;
    auto offsetPosY = (view->getContentOffset()).y ;
    parkSprite->setPosition(offsetPosX,offsetPosY);

    // printf("x==== %f\n",offsetPosX);
    // printf("y==== %f\n",offsetPosY);
    if( view->isDragging()) //正在拖动
	{

	}

}*/