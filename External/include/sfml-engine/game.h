#pragma once

#include <string>
class Game
{
    public:
        Game();
        Game(const std::string& title);
        ~Game();
        void Run();
    protected:
        virtual void Update(float deltaTime){}
        void Start();
        void UpdatePhysics(float fixedDeltaTime){};
        void Draw();

    private:
        void InitializeServices();
        void ShutdownServices();

    private:
        std::string m_title;
        bool m_isRunning;
};

extern Game* CreateGame();