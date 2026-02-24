#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(HiButtonMenuLayer, MenuLayer) {
public:
    bool init() {
        if (!MenuLayer::init())
            return false;

        // your demon PNG from resources/icon.png
        auto btnSpr = CCSprite::create("icon.png");

        // button that plays last.wav when clicked
        auto btn = CCMenuItemSpriteExtra::create(
            btnSpr,
            this,
            menu_selector(HiButtonMenuLayer::onHiButton)
        );

        // attach to the main menu so it ACTUALLY shows on Android
        auto menu = this->m_buttonMenu;
        menu->addChild(btn);

        // visible position
        btn->setPosition({200, 200});

        return true;
    }

    void onHiButton(CCObject*) {
        // play your audio file from resources/last.wav
        FMODAudioEngine::sharedEngine()->playEffect("last.wav");
    }
};
