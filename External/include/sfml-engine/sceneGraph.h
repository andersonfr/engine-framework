#pragma once
#include <sfml-engine/platform/sfml_node.h>

class SceneGraph
{
    public:
        SceneGraph(){ m_graph = std::make_unique<SFMLNode>();}
        const std::unique_ptr<SFMLNode>& GetScene() { return m_graph;}
    private:
        std::unique_ptr<SFMLNode> m_graph;

};