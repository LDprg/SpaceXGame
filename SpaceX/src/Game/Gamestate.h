#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.h"

class Game;

// DON'T CALL ANY PURE VIRTUAL FUNCTIONS IN THIS CLASS
class Gamestate
{
public:
	virtual void Create(Game& game) = 0;
	virtual void Destroy(Game& game) = 0;

	virtual void HandleEvents(Game& game, sf::Event& events) = 0;
	virtual void Update(Game& game) = 0;
	virtual void Draw(Game& game) = 0;

	virtual std::string GetName() {
		return "Gamestate";
	}

	virtual ~Gamestate() {
		std::cout << "State: \"" << GetName() << "\" destroyed!" << std::endl;
	}
};