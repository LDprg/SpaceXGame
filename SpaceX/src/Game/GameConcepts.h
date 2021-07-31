#pragma once

#include <type_traits>

#include "Gamestate.h"

class Gamestate;

template<class T>
concept Gamestates = std::is_base_of<Gamestate, T>().value;