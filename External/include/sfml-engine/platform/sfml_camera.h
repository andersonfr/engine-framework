#include <sfml-engine/camera.h>

class SFMLCamera : public Camera
{
public:
    SFMLCamera(){}
public:
    const sf::View & GetCameraView() { return m_view;}
    void SetViewCenter(const sf::Vector2f& center ) { m_view.setCenter(center);}
    void SetViewport(const sf::FloatRect& rect) {m_view.setViewport(rect);}
private:
    sf::View m_view;
};