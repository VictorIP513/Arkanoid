#include "..\headers\platform.h"
#include "..\headers\ball.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(General::gameWidth, General::gameHeight), "Arkanoid", Style::Close);
	Platform platform(window, Color::Yellow);
	Ball ball(window, Color::Yellow);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		window.clear();
		platform.draw_platform();
		ball.draw_ball();
		window.display();
	}
	return 0;
}