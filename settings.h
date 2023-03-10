#pragma once
#include <SFML/Graphics.hpp>
const int WINDOW_HEIGHT = 800.f;
const int WINDOW_WIDTH = 800.f;
const std::string WINDOW_TITLE{ "SFML Road Fighter" };
const unsigned int FPS{ 60 };
const sf::Vector2f ROAD_POS{ 150.f, 0.f };
const sf::Vector2f GRASS_POS{ 0.f, 0.f };
const sf::Vector2f ROAD_POS1{ 150.f, -800.f };
const sf::Vector2f GRASS_POS1{ 0.f, -800.f };
const int CAR_SPEEDX = 3.f;
const sf::Vector2f CAR_START_POS{ 350.f,600.f };
const unsigned int FONT_SIZE = 75;
const sf::Vector2f TEXT_POS{ 680.f,325.f };