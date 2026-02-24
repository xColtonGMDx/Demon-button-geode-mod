#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(HiButtonMenuLayer, MenuLayer) {
public:
    bool init() {
        if (!MenuLayer::init())
            return false;

        // Find the title sprite
        auto title = this->getChildByID("main-menu");
        if (!title)
            return true;

        // Create button sprite (Android-safe)
        auto btnSpr = CCSprite::create("icon.png");   // <-- ADDED THIS LINE

        // Create button
        auto btn = CCMenuItemSpriteExtra::create(
            btnSpr,
            this,
            menu_selector(HiButtonMenuLayer::onHiButton)
        );

        // --- REPLACED CHUNK: guaranteed visible position ---
        btn->setPosition({200, 200});

        // Add to menu
        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(0, 0);
        this->addChild(menu);

        return true;
    }

    void onHiButton(CCObject*) {
        // --- Android-safe popup replacement ---
        auto layer = CCLayerColor::create({0, 0, 0, 180});

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto bg = CCSprite::create("GJ_square01.png");
        bg->setScale(2.0f);
        bg->setPosition(winSize / 2);
        layer->addChild(bg);

        auto label = CCLabelBMFont::create("hi :) im useless", "gjFont.fnt");
        label->setPosition(winSize / 2);
        layer->addChild(label);

        auto closeBtn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"),
            this,
            menu_selector(HiButtonMenuLayer::onClose)
        );

        auto menu = CCMenu::create();
        menu->addChild(closeBtn);
        menu->setPosition(winSize.width / 2 + 120, winSize.height / 2 + 120);
        layer->addChild(menu);

        layer->setTag(999);

        CCDirector::sharedDirector()->getRunningScene()->addChild(layer, 999);
    }

    // --- ONLY ADDITION YOU ASKED FOR ---
    void onClose(CCObject*) {
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        scene->removeChildByTag(999);
    }
};
