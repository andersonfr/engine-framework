#pragma once
#include <string>

struct WindowData
{
    int width;
    int height;
    std::string title;
};

class Window
{
    public:
        virtual void OpenWindow(WindowData data) = 0;
        virtual void Draw() = 0;
        virtual bool Update() = 0;
        virtual bool IsOpen() = 0;

        virtual float GetWidth() = 0;
        virtual float GetHeight() = 0;
};