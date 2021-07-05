#pragma once

#include <SFML/Graphics.hpp>

#include <filesystem>
#include <direct.h>
#include <sfml-engine/service_locator.h>
#include <sfml-engine/game.h>

int main(int argc, char** argv)
{   
    // const auto& window = ServiceLocator::GetWindow();

    // window->OpenWindow();
    // window->Update();
    auto game = std::unique_ptr<Game>(CreateGame());
    game->Run();
    // sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    // Resources::Get().LoadResource<sf::Texture>("filename.jpg");
    // auto& textureHandle = Resources::Get().GetResource<TextureHandle>("filename.jpg");

    // char tmp[256];
    // getcwd(tmp, 256);
    // std::cout << "Current working directory: " << tmp << std::endl;
    // sf::Sprite s;
    // s.setTexture(textureHandle.GetTexture());
    
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }
        
    //     window.clear();
        
    //     window.draw(shape);
    //     window.draw(s);
        
    //     window.display();
    // }
    return 0;
}