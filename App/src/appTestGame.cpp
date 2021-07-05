#include "appTestGame.h"
#include "myObject.h"
#include <iostream>
#include <sfml-engine/service_locator.h>
#include <sfml-engine/platform/sfml_window.h>

AppTestGame::AppTestGame(std::string title) : Game(std::move(title))
{
    std::cout << "Hello I'm Test App" << std::endl;
    auto* window = static_cast<SFMLWindow*>(ServiceLocator::GetWindow().get());
    auto myObject = std::make_unique<MyObject>();
    ServiceLocator::GetSceneGraph()->GetScene()->AttachChild(std::move(myObject));	
}

void AppTestGame::Update(float deltaTime)
{
     //std::cout << "Hello I'm Test App" << std::endl;
}