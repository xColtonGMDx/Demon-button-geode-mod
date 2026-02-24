#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(HiButtonMenuLayer, MenuLayer) {
public:
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto title = this->getChildByID("game-title");
        if (!title)
            return true;

        auto btnSpr = CCSprite::createWithSpriteFrameName("GJ_button_01.png");

        auto btn = CCMenuItemSpriteExtra::create(
            btnSpr,
            this,
            menu_selector(HiButtonMenuLayer::onHiButton)
        );

        auto pos = title->getPosition();
        float offset = title->getContentSize().width * title->getScale() / 2 + 50.f;
        btn->setPosition(pos.x + offset, pos.y);

        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(0, 0);
        this->addChild(menu);

        return true;
    }

    void onHiButton(CCObject*) {
        auto layer = CCLayerColor::create({0, 0, 0, 180});
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto bg = CCSprite::create("GJ_square01.png");
        bg->setScale(2.0f);
        bg->setPosition(winSize / 2);
        layer->addChild(bg);

        auto label = CCLabelBMFont::create("hi :) im useless", "bigFont.fnt");
        label->setPosition(winSize / 2);
        layer->addChild(label);

        // CLOSE BUTTON (fixed)
        auto closeSpr = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
        auto closeBtn = CCMenuItemSpriteExtra::create(
            closeSpr,
            this,
            menu_selector(HiButtonMenuLayer::onClosePopup)
        );

        auto menu = CCMenu::create();
        menu->addChild(closeBtn);
        menu->setPosition(winSize.width / 2 + 120, winSize.height / 2 + 120);
        layer->addChild(menu);

        layer->setTag(999);

        CCDirector::sharedDirector()->getRunningScene()->addChild(layer, 999);
    }

    void onClosePopup(CCObject*) {
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        scene->removeChildByTag(999);
    }
};
