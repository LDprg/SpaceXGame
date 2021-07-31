#include "TextButton.h"

TextButton::TextButton()
{
	font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");
	button.setFont(font);
	button.setFillColor(sf::Color::Red);
	button.setPosition(sf::Vector2f(0.f, 0.f));
	button.setCharacterSize(20);
	button.setString("Test");
}

TextButton::~TextButton()
{
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(button, states);
}
