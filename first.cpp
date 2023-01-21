
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(600, 600), "tags");
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("arhip.ttf");


	sf::Text text("F2 is a New Game / Esc is an Exit / Arrow Keys is a Move Tile", font, 20);
	text.setFillColor(sf::Color::Cyan);
	text.setPosition(5.f, 5.f);

	Game game;
	game.setPosition(50.f, 50.f);

	sf::Event event;
	int move_counter{0};

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
			
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);
			
				if (event.key.code == sf::Keyboard::F2)
				{
					game.Init();
					move_counter = 100;
				}
			}
		}

		if ((move_counter --) > 0) game.Move((Direction)(rand() % 4));

	
		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}