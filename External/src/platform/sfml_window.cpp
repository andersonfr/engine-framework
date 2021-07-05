#include <sfml-engine/platform/sfml_window.h>
#include <sfml-engine/service_locator.h>

SFMLWindow::~SFMLWindow()
{
    m_window.reset();
    m_window = nullptr;
}

void SFMLWindow::OpenWindow(WindowData data)
{
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(data.width, data.height), data.title);
}

bool SFMLWindow::Update()
{
    sf::Event event;
    while(m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window->close();
    }
    return IsOpen();
}

void SFMLWindow::Draw()
{
    m_window->clear();
    m_window->draw(*ServiceLocator::GetSceneGraph()->GetScene());
    m_window->display();
}

bool SFMLWindow::IsOpen()
{
    return m_window->isOpen();
}