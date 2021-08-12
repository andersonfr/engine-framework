#pragma once
#include <sfml-engine/platform/sfml_sprite_node.h>

class MyObject : public SFMLSpriteNode
{
    public:
        MyObject();
        virtual ~MyObject() = default;

        //void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        void updateCurrent(float deltaTime) override;
        void startCurrent() override;
        sf::Sprite m_sprite;
        
};
