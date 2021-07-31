#pragma once
#include <memory>
#include <assert.h>

#include <SFML/Graphics.hpp>

#include "GameConcepts.h"
#include "Gamestate.h"

#include "../Gamestates/Menuestate.h"

class Gamestate;

class Game
{
public:
	Game();
	~Game();

	template<Gamestates T>
	void Run() {
		load<T>();
		Run();
	}

	sf::RenderWindow& getWindow() { return m_window; }
	sf::Color& getWindowColor() { return m_windowColor; }

	float getDeltaTime() { return m_deltaTime; }
	float getFPS() { return (1.f / getDeltaTime()); }

private:
	sf::RenderWindow m_window;
	sf::Color m_windowColor;

	std::unique_ptr<Gamestate> m_state;

	sf::Clock m_deltaClock;
	float m_deltaTime;

	template<Gamestates T>
	void load()
	{
		if (m_state)
			DestroyState();

		m_state = std::make_unique<T>();

		CreateState();
	}

	void CreateState();
	void DestroyState();

	void Run();
};