#include "CocosGUIScene.h"
#include "CocosGUIExamplesScene.h"
#include "ExtensionsTest.h"

void runCocosGUITestLayer()
{
    CCScene *pScene = CocosGUITestLayer::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
}

CocosGUITestLayer::~CocosGUITestLayer()
{
}

CocosGUITestLayer::CocosGUITestLayer()
{

}

CCScene* CocosGUITestLayer::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		CocosGUITestLayer *layer = CocosGUITestLayer::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

bool CocosGUITestLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    ul = UILayer::create();
    ul->scheduleUpdate();
    this->addChild(ul);
    
    
    CCMenuItemFont *itemBack = CCMenuItemFont::create("Back", this, menu_selector(CocosGUITestLayer::toExtensionsMainLayer));
        itemBack->setColor(ccc3(255, 255, 255));
        itemBack->setPosition(ccp(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
        CCMenu *menuBack = CCMenu::create(itemBack, NULL);
        menuBack->setPosition(CCPointZero);
		menuBack->setZOrder(4);
    this->addChild(menuBack);
    
//    UILayer* ul2 = UILayer::create();
//    this->addChild(ul2);
//    
//    UIPanel* p1 = UIPanel::create();
//    p1->setBackGroundImageScale9Enable(true);
//    p1->setBackGroundColorType(PANEL_COLOR_GRADIENT);
//    p1->setBackGroundColor(ccGREEN,ccWHITE);
//    p1->setOpacity(255);
//    p1->setPosition(ccp(100, 100));
//    p1->setSize(CCSizeMake(100, 100));
//    p1->setTouchEnable(true);
//    p1->addReleaseEvent(this, coco_releaseselector(CocosGUITestScene::MainMenuCallback));
//    
//    UIPanel* p2 = UIPanel::create();
//    p2->setBackGroundImageScale9Enable(true);
//    p2->setBackGroundColorType(PANEL_COLOR_SOLID);
//    p2->setBackGroundColor(ccGREEN);
//    p2->setOpacity(255);
//    p2->setPosition(ccp(150, 150));
//    p2->setSize(CCSizeMake(100, 100));
//    p2->setTouchEnable(true);
//    p2->addReleaseEvent(this, coco_releaseselector(CocosGUITestScene::toCocosGUISlotScene));
//    
//    ul->unscheduleUpdate();
//    CCLOG("p1 retain count == %d",ul->retainCount());
//    
//    ul->addWidget(p1);
//    ul2->addWidget(p2);
//    return;
    
    

    ul->addWidget(CCUIHELPER->createWidgetFromJsonFile("cocosgui/CocoGUISample.json"));

    UIButton* exitBtn = dynamic_cast<UIButton*>(ul->getWidgetByName("exitbutton"));
    exitBtn->addReleaseEvent(this, coco_releaseselector(CocosGUITestLayer::toCocosGUIExampleScene));
    
    return true;
}

void CocosGUITestLayer::toExtensionsMainLayer(cocos2d::CCObject *sender)
{
    ul->removeFromParent();

	ExtensionsTestScene *pScene = new ExtensionsTestScene();
	pScene->runThisTest();
	pScene->release();
}

void CocosGUITestLayer::toCocosGUIExampleScene(CCObject* pSender)
{
    CCLOG("p2 click");
    ul->removeFromParent();
    
    CCScene *pScene = CocosGUIExampleLayer::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
    
//    CCScene *pScene = SceneEditorTestLayer::scene();
//    CCDirector::sharedDirector()->replaceScene(pScene);
    
//    CocosGUIExamplesScene* pScene = new CocosGUIExamplesScene();
//    if (pScene)
//    {
//        pScene->runThisTest();
//        pScene->release();
//    }
}
