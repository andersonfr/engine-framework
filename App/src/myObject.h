#pragma once
#include <sfml-engine/platform/sfml_node.h>

class MyObject : public SFMLNode
{
    public:
        MyObject();
        virtual ~MyObject() = default;

        void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        void updateCurrent(float deltaTime) override;
        void startCurrent() override;
        sf::Sprite m_sprite;
};
