#pragma once
#include <sfml-engine/platform/window.h>
#include "SFML/Graphics.hpp"
#include <sfml-engine/platform/sfml_node.h>

class SFMLWindow : public Window
{
    public:
        SFMLWindow(){}
        virtual ~SFMLWindow();        
        void OpenWindow(WindowData data) override;
        void Draw() override;
        
        bool Update() override;
        bool IsOpen() override;

        float GetWidth() override { return m_window->getSize().x;}
        float GetHeight() override { return m_window->getSize().y;}

        void SetView(const sf::View& view) {m_window->setView(view);}

    private:
        std::unique_ptr<sf::RenderWindow> m_window;
};
