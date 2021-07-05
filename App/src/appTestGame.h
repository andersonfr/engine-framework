#pragma once
#include <sfml-engine/game.h>

class AppTestGame : public Game
{
    public:
        AppTestGame(std::string title);
    protected:
        void Update(float deltaTime) override;        
};