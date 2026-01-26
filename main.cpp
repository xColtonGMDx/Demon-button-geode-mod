#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(HiButtonMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        // Try to find the title sprite
        CCSprite* title = nullptr;

        // First try ID-based lookup (newer GD versions)
        title = this->getChildByID("game-title");

        // Fallback: search for the logo sprite manually
        if (!title) {
            CCArray* children = this->getChildren();
            CCObject* obj;
            CCARRAY_FOREACH(children, obj) {
                if (auto spr = typeinfo_cast<CCSprite*>(obj)) {
                    auto name = spr->getDisplayFrame()->getTexture()->getName();
                    // crude heuristic: the title is usually the largest sprite
                    if (!title || spr->getScale() > title->getScale()) {
                        title = spr;
                    }
                }
            }
        }

        if (!title)
            return true;

        // Create Extreme Demon face sprite
        auto sprite = CCSprite::createWithSpriteFrameName("demonIcon_001.png");
        if (!sprite)
            sprite = CCSprite::createWithSpriteFrameName("GJ_demonIcon_001.png");

        auto btn = CCMenuItemSpriteExtra::create(
            sprite,
            sprite,
            this,
            menu_selector(HiButtonMenuLayer::onHiButton)
        );

        // Create a menu to hold the button
        auto menu = CCMenu::create();
        menu->setPosition({0, 0});
        this->addChild(menu);

        // Position the button to the RIGHT of the title
        auto pos = title->getPosition();
        float offset = title->getContentSize().width * title->getScale() / 2 + 50.f;

        btn->setPosition({ pos.x + offset, pos.y });

        menu->addChild(btn);

        return true;
    }

    void onHiButton(CCObject*) {
        FLAlertLayer::create("Hi", "hi", "OK")->show();
    }
};