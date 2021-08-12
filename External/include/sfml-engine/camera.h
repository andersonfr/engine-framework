#pragma once
#include "SFML/Graphics.hpp"

class Camera
{
protected:
    sf::Vector2f m_center;
    sf::Vector2f m_width;
    sf::Vector2f m_right;
};