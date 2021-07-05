#include <sfml-engine/platform/sfml_node.h>
#include <assert.h>

SFMLNode::SFMLNode(){}

void SFMLNode::AttachChild(std::unique_ptr<SFMLNode> node)
{
    node->m_parent = this;
    this->m_children.push_back(std::move(node));
}

std::unique_ptr<SFMLNode> SFMLNode::DetachChild(const SFMLNode& node)
{
    auto found = std::find_if(m_children.begin(), m_children.end(), 
    [&](std::unique_ptr<SFMLNode> & n ) { return &node == n.get(); } );

    assert(found != m_children.end() && "Child not found");

    std::unique_ptr<SFMLNode> nodeFound = std::move(*found);
    nodeFound->m_parent = nullptr;
    m_children.erase(found);

    return std::move(nodeFound);
}

void SFMLNode::Start()
{
    startCurrent();
    std::for_each(m_children.begin(), m_children.end(), [&](std::unique_ptr<SFMLNode> & node) { node->Start();} );
}

void SFMLNode::Update(float deltaTime)
{
    updateCurrent(deltaTime);
    std::for_each(m_children.begin(), m_children.end(), [&](std::unique_ptr<SFMLNode> & node) { node->Update(deltaTime);} );
}

void SFMLNode::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();

    DrawCurrent(target,states);

    std::for_each(m_children.begin(), m_children.end(), [&](const std::unique_ptr<SFMLNode> & node) { node->draw(target,states);} );
}