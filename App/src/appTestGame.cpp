#include "appTestGame.h"
#include "myObject.h"
#include <iostream>
#include <sfml-engine/service_locator.h>
#include <sfml-engine/platform/sfml_window.h>

AppTestGame::AppTestGame(std::string title) : Game(std::move(title))
{
   
}

void AppTestGame::Start()
{
    std::cout << "Hello I'm Test App" << std::endl;
    Game::Start();
    auto* window = static_cast<SFMLWindow*>(ServiceLocator::GetWindow().get());
    auto myObject = std::make_unique<MyObject>();
    ServiceLocator::GetSceneGraph()->GetScene()->AttachChild(std::move(myObject));
    auto* camera = static_cast<SFMLCamera*>(ServiceLocator::GetCamera().get());
    camera->SetViewport(sf::FloatRect(0.0f,0.0f,1.0f,1.0f));
    camera->SetViewCenter({400,300});
    window->SetView(camera->GetCameraView());
}

void AppTestGame::Update(float deltaTime)
{
    ServiceLocator::GetSceneGraph()->GetScene()->Update(0);
    //auto* window = static_cast<SFMLWindow*>(ServiceLocator::GetWindow().get());
    //std::cout << window->GetWidth() << std::endl;
}