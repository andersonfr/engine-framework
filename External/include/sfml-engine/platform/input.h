#pragma once
#include <map>
#include "SFML/Graphics.hpp"

enum class EKeyBinds
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    PAUSE,
};

class Input
{
public:
    Input()
    {

    }
};

class SFMLInput
{
public:
    std::map<EKeyBinds, sf::Keyboard::Key> m_keyBindings;

    virtual sf::Keyboard::Key GetKeyPressed(EKeyBinds keybind) = 0;
};

class SFMLInputKeyBoard : public SFMLInput
{
public:
    SFMLInputKeyBoard()
    {
        //default
        SetKey(EKeyBinds::UP, sf::Keyboard::Key::Up);
    }
    virtual ~SFMLInputKeyBoard() = default;

    sf::Keyboard::Key GetKeyPressed(EKeyBinds keybind) override
    {
        return m_keyBindings[keybind];
    }

    void SetKey(EKeyBinds keybind, sf::Keyboard::Key key)
    {
        m_keyBindings[keybind] = key;
    }
};