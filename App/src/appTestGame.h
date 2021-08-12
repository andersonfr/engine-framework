#pragma once
#include <sfml-engine/game.h>

class AppTestGame : public Game
{
    public:
        AppTestGame(std::string title);
        virtual ~AppTestGame() = default;
    protected:
        void Update(float deltaTime) override;
        void Start() override;
};