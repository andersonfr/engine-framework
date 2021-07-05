#include "myObject.h"
#include <sfml-engine/platform/engine.h>

MyObject::MyObject()
{

}

void MyObject::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
}

void MyObject::startCurrent()
{
    if(Resources::Get().LoadResource<sf::Texture>("filename.jpg"))
    {
        const auto& handle = Resources::Get().GetResource<TextureHandle> ("filename.jpg");
        m_sprite.setTexture(handle.GetTexture());
    }
}

void MyObject::updateCurrent(float deltaTime)
{

}