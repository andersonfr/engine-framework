#include "imgui-SFML.h"
#include "imgui.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    std::cout<<"hello world"<<std::endl;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    ImGui::SFML::Init(window);
    sf::Color shapeColor;
    float color[3] = {0.f, 1.0f, 0.f};
    window.setTitle("Imgui + Sfml");
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::Begin("Sample Window");

        if(ImGui::ColorEdit3("Shape Color",color))
        {
            shapeColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
            shapeColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
            shapeColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
        }
        ImGui::End();
        window.clear();
        shape.setFillColor(shapeColor);
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}