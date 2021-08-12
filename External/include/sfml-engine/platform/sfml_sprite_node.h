#pragma once
#include <sfml-engine/platform/sfml_node.h>

class SFMLSpriteNode : public SFMLNode 
{
public:
    SFMLSpriteNode() : m_texture( NULL ){}
    SFMLSpriteNode(const std::string& source, sf::Vector2i frames);
    ~SFMLSpriteNode() = default;
    
    void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
    void SetupTexture(int width = 32, int height = 32, int coordX = 0, int coordY = 0);
private:
    virtual void updateCurrent(float deltaTime){}
    virtual void startCurrent(){}
    sf::VertexArray m_vertices;
    sf::Texture* m_texture;
};