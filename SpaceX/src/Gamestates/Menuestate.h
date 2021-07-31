#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

#include "../Game/Gamestate.h"

#include "../GUI/TextButton.h"

class Menuestate : public Gamestate
{
public:
	virtual void Create(Game& game) override;
	virtual void Destroy(Game& game) override;

	virtual void HandleEvents(Game& game, sf::Event& events) override;
	virtual void Update(Game& game) override;
	virtual void Draw(Game& game) override;
	virtual std::string GetName() override;

private:
	TextButton m_button;
};

