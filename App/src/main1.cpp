// #include "imgui-SFML.h"
// #include "imgui.h"
// #include "imgui_internal.h"
// #include <iostream>
// #include <SFML/Graphics.hpp>
// #include <vector>
// #include "cmath"

//  #define IMGUI_DEFINE_MATH_OPERATORS

// enum class EFace
// {
//     ONE   = 1 << 1,
//     TWO   = 1 << 2,
//     THREE = 1 << 3,
//     FOUR  = 1 << 4,
//     FIVE  = 1 << 5,
//     SIX   = 1 << 6
// };

// template<class T>
// class KeyPoint
// {
// public:
//     KeyPoint(){}
//     KeyPoint(T key, float t)
//     :m_key(key), m_t(t){}
//     float getTime(){return m_t;}
//     T getKey() {return m_key;}
// private:
//     T m_key;
//     float m_t;
// };

// template<class T>
// class Curve
// {
// public:
//     Curve(std::vector<KeyPoint<T>> points)
//     : m_points (points)
//     {

//     }
    

//     T lerp(T start, T end, T t)
//     {
//         return start*(1-t) + end * t;
//     }

//     T coserp(T start, T end, T t)
//     {
//         T pi = 2 * asin(1.0);
//         T t2;
//         t2 = (1-cos(t* pi))/2;

//         return lerp(start,end,t2);
//     }

//     T evaluate(T elapsed)
//     {
//         if(m_points.size() == 0)
//             return T();

//         KeyPoint<T> a, b;
//         a = m_points[0];
        
//         elapsed = fmod(elapsed, 4.0f);

//         for(int i = 0; i < m_points.size(); i++)
//         {
//             if ( elapsed > m_points[i].getTime())
//             {
//                 a = m_points[i];
//                 b = a;
               
//             }
//             else if( elapsed <= m_points[i].getTime())
//             {
//                 b = m_points[i];
//                 break;
//             }
//         }
//         if(a.getTime() == b.getTime())
//             return a.getKey();
//         //normalize time interval
//         T diff = b.getTime() - a.getTime();
//         T t = (elapsed - a.getTime()) / diff;
//         //interpolate find begin and end
//         return coserp(a.getKey(), b.getKey(), t);
//     }
// private:
//     std::vector<KeyPoint<T>> m_points;
// };
// namespace ImGui
// {
//     int curve(const std::string& label, const ImVec2& size, int maxPoints, ImVec2* points )
//     {
//         int modified = 0;
//         int i = 0;
//         if(maxPoints < 2  || points == nullptr)
//             return 0;
        
//         if(points[0].x < 0 )
//         {
//             points[0].x = 0;
//             points[0].y = 0;
//             points[1].x = 0;
//             points[1].y = 0;
//             points[2].x = -1;
//         }

//         ImGuiWindow* window = GetCurrentWindow();
//         ImGuiContext& g = *GImGui;
//         const  ImGuiStyle& style = g.Style;

//         const ImGuiID id = window->GetID(label.data());
//         if(window->SkipItems)
//             return 0;

//         ImVec2 min = window->DC.CursorPos;
//         ImVec2 max = { window->DC.CursorPos.x + size.x, window->DC.CursorPos.y + size.y };
//         ImRect bb(min, max);
//         ItemSize(bb);

//         if(!ItemAdd(bb,id))
//         {
//             return 0;
//         }

//         const bool isHovered = IsItemHovered();

//         RenderFrame(bb.Min, bb.Max, GetColorU32(ImGuiCol_FrameBg, 1), true, style.FrameRounding);

//         float ht = bb.Max.y - bb.Min.y;
//         float wd = bb.Max.x - bb.Min.x;

//         window->DrawList->AddLine
//         (
//             ImVec2(bb.Min.x, bb.Min.y +  ht/2),
//             ImVec2(bb.Min.x, bb.Min.y +  ht/2),
//             GetColorU32(ImGuiCol_TextDisabled),
//             3
//         );

//         window->DrawList->AddLine(
//             ImVec2(bb.Min.x, bb.Min.y + ht / 4),
//             ImVec2(bb.Max.x, bb.Min.y + ht / 4),
//             GetColorU32(ImGuiCol_TextDisabled));

//         window->DrawList->AddLine(
//             ImVec2(bb.Min.x, bb.Min.y + ht / 4 * 3),
//             ImVec2(bb.Max.x, bb.Min.y + ht / 4 * 3),
//             GetColorU32(ImGuiCol_TextDisabled));
        
//         for (i = 0; i < 9; i++)
//         {
//             window->DrawList->AddLine(
//                 ImVec2(bb.Min.x + (wd / 10) * (i + 1), bb.Min.y),
//                 ImVec2(bb.Min.x + (wd / 10) * (i + 1), bb.Max.y),
//                 GetColorU32(ImGuiCol_TextDisabled));
//         }
//         enum { smoothness = 256 }; // the higher the smoother
//         for( i = 0; i <= (smoothness-1); ++i ) {
//             float px = (i+0) / float(smoothness);
//             float qx = (i+1) / float(smoothness);
//             float py = 1 - 100;
//             float qy = 1 - 100;
//             ImVec2 p( px * (bb.Max.x - bb.Min.x) + bb.Min.x, py * (bb.Max.y - bb.Min.y) + bb.Min.y);
//             ImVec2 q( qx * (bb.Max.x - bb.Min.x) + bb.Min.x, qy * (bb.Max.y - bb.Min.y) + bb.Min.y);
//             window->DrawList->AddLine(p, q, GetColorU32(ImGuiCol_PlotLines));
//         } 
        
//         if(isHovered)
//             return 1;
        

//         return 0;
//     }

// }

// int main(int argc, char** argv)
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);
//     ImGui::SFML::Init(window);
//     float color[3] = {0.f, 1.0f, 0.f};
//     sf::Color shapeColor 
//     {
//         static_cast<sf::Uint8>(color[0] * 255.0f), 
//         static_cast<sf::Uint8>(color[1] * 255.0f), 
//         static_cast<sf::Uint8>(color[2] * 255.0f)
//     };
//     ImVec2 foo[10];
//     foo[0].x = -1;

//     std::vector<KeyPoint<float>> keyPoints
//     {
//         {0.0f, 0.0f}, {0.5f,2.5f}, {1.0f, 3.0f}, {0.0f, 4.0f}
//     };
//     Curve<float> curve { keyPoints };

//     window.setTitle("Imgui + Sfml");
//     sf::Clock deltaClock;
//     sf::Time elapsed = sf::Time::Zero;
//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             ImGui::SFML::ProcessEvent(event);
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         elapsed += deltaClock.getElapsedTime();
//         float alpha = curve.evaluate(elapsed.asSeconds());
//         ImGui::SFML::Update(window, deltaClock.restart());
//         if(ImGui::curve("Test",ImVec2(600, 200), 10, foo))
//         {
//             std::cout << "curve changed" << std::endl;
//         }
//         // ImGui::Begin("Sample Window");
//         // if(ImGui::ColorEdit3("Shape Color",color))
//         // {
//         //     shapeColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
//         //     shapeColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
//         //     shapeColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
//         // }
//         // ImGui::End();
//         shapeColor.a = static_cast<sf::Uint8>(alpha * 255.f);
//         window.clear();
//         shape.setFillColor(shapeColor);
//         window.draw(shape);
//         ImGui::SFML::Render(window);
//         window.display();
//     }

//     ImGui::SFML::Shutdown();
//     return 0;
// }