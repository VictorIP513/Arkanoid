#include "platform.h"
#include "ball.h"

int main()
{
	RenderWindow *window = new RenderWindow(VideoMode(General::gameWidth, General::gameHeight), "Arkanoid", Style::Close);
	Platform *platform = new Platform(*window);
	Ball *ball = new Ball(*window, *platform);
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window->close();
		window->clear();
		platform->draw();
		ball->draw();
		window->display();
	}
	return 0;
}