#include "..\headers\platform.h"


Platform::Platform(RenderWindow &window) : 
				window(&window),
				coord((gameWidth + size.x) / 2, gameHeight - 44),
				size(200, 25),
				color(Color::Cyan)			
{}

Platform::Platform(RenderWindow &window, Color color) :
				window(&window),
				color(color),
				coord((gameWidth + size.x) / 2, gameHeight - 44),
				size(200, 25)
{}

Platform::Platform(RenderWindow &window, Color color, Vector2f size) :
				window(&window),
				color(color),
				size(size),
				coord((gameWidth + size.x) / 2, gameHeight - 44)
{}

void Platform::draw_platform()
{
	platform.setPosition(coord);
	platform.setSize(size);
	platform.setFillColor(color);
	window->draw(platform);
	Vector2i q = Mouse::getPosition(*window);
	coord.x = Mouse::getPosition(*window).x;
	//(Vector2i)coord = Mouse::getPosition(*window);
	//std::cout << Mouse::getPosition(*window).x << " " << Mouse::getPosition(*window).y << std::endl;
	std::cout << coord.x;
}
