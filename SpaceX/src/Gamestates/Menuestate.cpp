#include "Menuestate.h"

void Menuestate::Create(Game& game)
{
    
}

void Menuestate::Destroy(Game& game)
{
}

void Menuestate::HandleEvents(Game& game, sf::Event& events)
{
    switch (events.type)
    {
    case sf::Event::Closed:
        game.getWindow().close();
        break;
    default:
        break;
    }
}

void Menuestate::Update(Game& game)
{

}

void Menuestate::Draw(Game& game)
{
    game.getWindow().draw(m_button);
}

std::string Menuestate::GetName()
{
    return "Menue";
}