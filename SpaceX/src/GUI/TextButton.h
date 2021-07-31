#pragma once
#include <SFML/Graphics.hpp>

class TextButton :public sf::Drawable
{
public:
	TextButton();
	~TextButton();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::string Text;
	sf::Text button;
	sf::Font font;
};

