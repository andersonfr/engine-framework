#include <sfml-engine/game.h>
#include <sfml-engine/service_locator.h>
// #include <sfml-engine/platform/sfml_window.h>
// #include <sfml-engine/platform/input.h>

Game::Game(): Game("Default Title Game"){}

Game::Game(const std::string& title) : m_title(title), m_isRunning(true)
{
    InitializeServices();
}

Game::~Game()
{
    ShutdownServices();
}

void Game::Start()
{
      ServiceLocator::GetWindow()->OpenWindow(
        {
            800,
            600,
            m_title
        });
}

void Game::Run()
{
    Start();
    ServiceLocator::GetSceneGraph()->GetScene()->Start();
    while(m_isRunning)
    {
        if(!ServiceLocator::GetWindow()->Update())
        {
            m_isRunning = false;
            continue;
        }
        UpdatePhysics(0);
        Update(0);
        Draw();
    }
}

void Game::Draw()
{
    ServiceLocator::GetWindow()->Draw();
}

void Game::InitializeServices()
{
    ServiceLocator::Provide(new SFMLWindow());
    ServiceLocator::Provide(new SceneGraph());
    ServiceLocator::Provide(new Resources());
    ServiceLocator::Provide(new SFMLCamera());
    ServiceLocator::Provide(new SFMLInputKeyBoard());
}
void Game::ShutdownServices()
{
    ServiceLocator::ShutdownServices();
}
