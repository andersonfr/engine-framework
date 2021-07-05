#pragma once
#include <memory>
#include <sfml-engine/platform/window.h>
#include <sfml-engine/sceneGraph.h>

class ServiceLocator
{
    public:
        static inline const std::unique_ptr<Window>& GetWindow() { return m_window;}
        static inline const std::unique_ptr<SceneGraph>& GetSceneGraph() { return m_graph;}
        static inline void Provide(Window* window)
        {
            if(m_window != nullptr) return;
            m_window = std::unique_ptr<Window>(window);
        }
        static inline void Provide(SceneGraph* graph)
        {
            if(m_graph != nullptr) return;
            m_graph = std::unique_ptr<SceneGraph>(graph);
        }
        
        static inline void InitializeServices(){}
        static inline void ShutdownServices(){ ShutdownWindow();}
    private:
        static inline std::unique_ptr<Window> m_window = nullptr;
        static inline std::unique_ptr<SceneGraph> m_graph = nullptr;
        static inline void ShutdownWindow()
        {
            m_window.reset();
            m_window = nullptr;
        }
};