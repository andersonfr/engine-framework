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
    private:
        std::unique_ptr<sf::RenderWindow> m_window;
};
