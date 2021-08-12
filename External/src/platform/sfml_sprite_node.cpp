#include <sfml-engine/platform/sfml_sprite_node.h>
#include <sfml-engine/service_locator.h>

#define N_VERTICES 4

SFMLSpriteNode::SFMLSpriteNode(const std::string& source , sf::Vector2i frames) : SFMLNode()
{
    auto& resources = ServiceLocator::GetResources();
    if(!resources->LoadResource<sf::Texture>(source))
    {
        throw std::runtime_error("could not load the file");
    }

    auto& handle = resources->GetResource<TextureHandle>(source);
    m_texture = &handle.GetTexture();
    
    m_vertices.setPrimitiveType(sf::PrimitiveType::Quads);
    m_vertices.resize(N_VERTICES);

    sf::Vertex* quad = &m_vertices[0];

    const sf::Vector2i& tileSize = handle.GetTileSize();
    
    SetupTexture(frames.x, frames.y, tileSize.x, tileSize.y );
}

void SFMLSpriteNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = m_texture;
    target.draw(m_vertices,states);
}

void SFMLSpriteNode::SetupTexture(int width, int height, int coordX, int coordY)
{
    //update texture coordinates and position
    sf::Vertex* quad = &m_vertices[0];
    //define its 4 corners
    quad[0].position = sf::Vector2f(0,0);
    quad[1].position = sf::Vector2f(width,0);
    quad[2].position = sf::Vector2f(width,height);
    quad[3].position = sf::Vector2f(0,height);

    //define its texture coordinates
    quad[0].texCoords = sf::Vector2f( coordX * width, coordY* height);
    quad[1].texCoords = sf::Vector2f( (coordX  + 1)* width,  coordY * height);
    quad[2].texCoords = sf::Vector2f( (coordX  + 1)* width, (coordY + 1) * height);
    quad[3].texCoords = sf::Vector2f( coordX* width, (coordY + 1) * height);
}