#pragma once
#include <SFML/Graphics.hpp>

const int size = 4;						
const int array_size = size * size;		
const int field_size = 500;				
const int cell_size = 120;				

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Game : public sf::Drawable, public sf::Transformable
{
protected:
	int elements[array_size];
	int empty_index;
	bool solved;
	sf::Font font;
public:
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};