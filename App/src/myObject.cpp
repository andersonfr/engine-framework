#include "myObject.h"
#include <sfml-engine/service_locator.h>

MyObject::MyObject() : SFMLSpriteNode("creatures3_.png", {0,0})
{

}

// void MyObject::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
// {
//     states.texture = m_sprite.getTexture();
//     target.draw(m_sprite);
// }

void MyObject::startCurrent()
{
    // if(Resources::Get().LoadResource<sf::Texture>("creatures3_.png"))
    // {
    //     const auto& handle = Resources::Get().GetResource<TextureHandle> ("creatures3_.png");
    //     m_sprite.setTexture(handle.GetTexture());
    //     //m_sprite.setTextureRect()
    // }
    SetupTexture(32,32, 2,2);
    sf::Vector2f size = { ServiceLocator::GetWindow()->GetWidth(), ServiceLocator::GetWindow()->GetHeight()};   
    setPosition(size.x/ 2.0f ,size.y/2.0f);
    //setRotation(90);
}

void MyObject::updateCurrent(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(ServiceLocator::GetInput()->GetKeyPressed(EKeyBinds::UP)))
        std::cout << getPosition().x << " " <<getPosition().y << std::endl;
}