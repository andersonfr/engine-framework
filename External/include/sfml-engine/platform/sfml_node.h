#pragma once
#include <vector>
#include <memory>
#include "SFML/Graphics.hpp"

class SFMLNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        SFMLNode();

        std::unique_ptr<SFMLNode> DetachChild(const SFMLNode& node);
        void AttachChild(std::unique_ptr<SFMLNode> node);
        void Update(float deltaTime);
        void Start();
        virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {}
        
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        virtual void updateCurrent(float deltaTime){}
        virtual void startCurrent(){}
    private:
        std::vector<std::unique_ptr<SFMLNode>> m_children;
        SFMLNode* m_parent;
};