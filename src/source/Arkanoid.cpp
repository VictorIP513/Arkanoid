#include "platform.h"
#include "ball.h"
#include "information.h"
#include "level.h"

int main()
{
	RenderWindow *window = new RenderWindow(VideoMode(General::gameWidth, General::gameHeight), "Arkanoid", Style::Close);
	Level *level = new Level(*window);
	Information *information = new Information(*window, *level);
	Platform *platform = new Platform(*window);
	Ball *ball = new Ball(*window, *platform, *information, *level);
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window->close();
		window->clear();
		information->draw();
		platform->draw();
		level->draw();
		ball->draw();
		window->display();
	}
	return 0;
}