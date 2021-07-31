#include "Game.h"

Game::Game()
{
    m_window.create(sf::VideoMode(800, 600), "SFML WINDOW");
    m_windowColor = sf::Color::Black;
}

Game::~Game()
{
    DestroyState();
    m_window.close();
}

void Game::Run()
{
    float lastTime = 0;

    while (m_window.isOpen())
    {
        m_state->Update(*this);

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            m_state->HandleEvents(*this, event);
        }

        m_window.clear(m_windowColor);

        m_state->Draw(*this);

        m_window.display();

        float currentTime = m_deltaClock.getElapsedTime().asSeconds();
        m_deltaTime = currentTime - lastTime;
        lastTime = currentTime;
    }
}

void Game::CreateState()
{
    m_state->Create(*this);
}

void Game::DestroyState()
{
    m_state->Destroy(*this);
}
