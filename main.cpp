#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/FLAlertLayer.hpp>

using namespace geode::prelude;

class $modify(HiButtonMenuLayer, MenuLayer) {
public:
    bool init() {
        if (!MenuLayer::init())
            return false;

        // Find the title sprite
        auto title = this->getChildByID("game-title");
        if (!title)
            return true;

        // Create a button
        auto btnSpr = CCSprite::create("GJ_button_01.png");
        auto btn = CCMenuItemSpriteExtra::create(
            btnSpr,
            this,
            menu_selector(HiButtonMenuLayer::onHiButton)
        );

        // Position the button next to the title
        auto pos = title->getPosition();
        float offset = title->getContentSize().width * title->getScale() / 2 + 50.f;
        btn->setPosition(pos.x + offset, pos.y);

        // Add to menu
        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(0, 0);
        this->addChild(menu);

        return true;
    }

    void onHiButton(CCObject*) {
        FLAlertLayer::create("Hi", "hi", "OK")->show();
    }
};