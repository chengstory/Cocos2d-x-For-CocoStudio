#ifndef __TestCpp__CocosGUIScene__
#define __TestCpp__CocosGUIScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../testBasic.h"

using namespace cocos2d;
using namespace cocos2d::extension;

void runCocosGUITestLayer();

class CocosGUITestLayer : public CCLayer
{
public:
    CocosGUITestLayer();
	~CocosGUITestLayer();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, 
    // instead of returning 'id' in cocos2d-iphone
	virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();

	// implement the "static node()" method manually
	CREATE_FUNC(CocosGUITestLayer);

    //back to Extensions Main Layer
    void toExtensionsMainLayer(cocos2d::CCObject *sender);    
    
    void toCocosGUIExampleScene(CCObject* pSender);
    
    UILayer* ul;
};

#endif /* defined(__TestCpp__CocosGUIScene__) */
