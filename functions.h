#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "car.h"
#include "obstacle.h"

void carsCollided(Car& car, Obstacle& obs) {
	if (car.sprite.getGlobalBounds().intersects(obs.sprite.getGlobalBounds())) {
		respawn(obs);
		car.score = car.score-1;
	}
}
