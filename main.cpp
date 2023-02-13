#include <SFML/Graphics.hpp>
#include "settings.h"
#include "roadObj.h"
#include "car.h"
#include "obstacle.h"
#include "functions.h"
#include "TextObj.h"


using namespace sf;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close);
	window.setFramerateLimit(FPS);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2,0 });

	RoadObj road;
	roadObjInit(road, ROAD_POS, "road.jpg");
	RoadObj grass;
	roadObjInit(grass, GRASS_POS, "grass.jpg");
	RoadObj road1;
	roadObjInit(road1, ROAD_POS1, "road.jpg");
	RoadObj grass1;
	roadObjInit(grass1, GRASS_POS1, "grass.jpg");
	Car car;
	carInit(car, CAR_START_POS, "car.png");
	Obstacle obs;
	obstacleInit(obs);
	Textobj scoreText;
	TextobjInit(scoreText, std::to_string(car.score), TEXT_POS);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		roadObjUpdate(grass, GRASS_POS1);
		roadObjUpdate(road, ROAD_POS1);
		roadObjUpdate(grass1, GRASS_POS1);
		roadObjUpdate(road1, ROAD_POS1);
		carUpdate(car);
		obstacleUpdate(obs);
		TextobjUpdate(scoreText, car.score);

		//carsCollided(car, obs);
		if (car.sprite.getGlobalBounds().intersects(obs.sprite.getGlobalBounds())) {
			respawn(obs);
			car.score = car.score - 1;

		}

		window.clear();
		roadObjDraw(window, grass);
		roadObjDraw(window,road);
		roadObjDraw(window, grass1);
		roadObjDraw(window, road1);
		carDraw(window, car);
		obstacleDraw(window, obs);
		textDraw(window, scoreText);
		window.display();

	}

	return 0;
}