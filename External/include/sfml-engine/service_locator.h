#pragma once
#include <memory>
#include <sfml-engine/platform/window.h>
#include <sfml-engine/platform/sfml_window.h>
#include <sfml-engine/platform/sfml_camera.h>
#include <sfml-engine/sceneGraph.h>
#include <sfml-engine/resources.h>
#include <sfml-engine/platform/input.h>

class ServiceLocator
{
    public:
        static inline const std::unique_ptr<Window>& GetWindow() { return m_window;}
        static inline const std::unique_ptr<SceneGraph>& GetSceneGraph() { return m_graph;}
        static inline const std::unique_ptr<Resources>& GetResources() {return m_resources;}
        static inline const std::unique_ptr<Camera>& GetCamera() {return m_camera;}
        static inline const std::unique_ptr<SFMLInput>& GetInput() {return m_input;}
       
        template<typename T>
        static inline void Provide(T* service);

        template<>
        static inline void Provide<Window>(Window* window);
        template<>
        static inline void Provide<SceneGraph>(SceneGraph* graph);
        template<>
        static inline void Provide<Resources>(Resources* resource);
        template<>
        static inline void Provide<SFMLCamera>(SFMLCamera* camera);
        template<>
        static inline void Provide<SFMLWindow>(SFMLWindow* window);
        template<>
        static inline void Provide<SFMLInputKeyBoard>(SFMLInputKeyBoard* input);

        static inline void InitializeServices(){}
        static inline void ShutdownServices(){ ShutdownWindow();}
    private:
        static inline std::unique_ptr<Window> m_window = nullptr;
        static inline std::unique_ptr<Camera> m_camera = nullptr;
        static inline std::unique_ptr<SceneGraph> m_graph = nullptr;
        static inline std::unique_ptr<Resources> m_resources = nullptr;
        static inline std::unique_ptr<SFMLInput> m_input = nullptr;

        static inline void ShutdownWindow()
        {
            m_window.reset();
            m_window = nullptr;
        }
};

template<>
static inline void ServiceLocator::Provide(Window* window)
{
    if(m_window != nullptr) return;
        m_window = std::unique_ptr<Window>(window);
}

template<>
static inline void ServiceLocator::Provide(SFMLWindow* window)
{
    if(m_window != nullptr) return;
        m_window = std::unique_ptr<SFMLWindow>(window);
}

template<>
static inline void ServiceLocator::Provide(SceneGraph* graph)
{
    if(m_graph != nullptr) return;
        m_graph = std::unique_ptr<SceneGraph>(graph);
}

template<>
static inline void ServiceLocator::Provide(Resources* resources)
{
    if(m_resources != nullptr) return;
        m_resources = std::unique_ptr<Resources>(resources);
}

template<>
static inline void ServiceLocator::Provide(SFMLCamera* camera)
{
    if(m_camera != nullptr ) return;
        m_camera = std::unique_ptr<SFMLCamera>(camera);
}

template<>
static inline void ServiceLocator::Provide(SFMLInputKeyBoard* input)
{
    if(m_input != nullptr) return;
        m_input = std::unique_ptr<SFMLInputKeyBoard>(input);
}