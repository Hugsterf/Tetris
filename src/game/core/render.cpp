#include "render.h"
#include "field.h"
#include "config.h"
#include "window.h"
#include "forms.h"
#include "gameLogic.h"

int Render::count = 0;

void Render::renderField()
{
	for (size_t i = 0; i < Config::GRID_HEIGHT; i++)
	{
		for (size_t j = 0; j < Config::GRID_WIDTH; j++)
		{
			sf::RectangleShape shape(sf::Vector2f(Config::CELL_SIZE, Config::CELL_SIZE));

			auto& cell = Field::getCell(i, j);

			shape.setFillColor(cell.getColor());
			shape.setPosition(sf::Vector2f(cell.getPosX(), cell.getPosY()));

			sf::RenderWindow& window = Window::getWindow();
			window.draw(shape);
		}
	}
}

void Render::pollEvent()
{
	sf::Event event;
	while (Window::pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window::close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::D:
				GameLogic::moveRight();
				break;
			case sf::Keyboard::A:
				GameLogic::moveLeft();
				break;
			}
		}
	}
}

void Render::renderBorder()
{
	sf::RectangleShape shape(sf::Vector2f(
		Config::GRID_TOTAL_WIDTH + 10,
		Config::GRID_TOTAL_HEIGHT + 10
	));

	shape.setPosition(
		Config::GRID_START_X - 5,
		Config::GRID_START_Y - 5
	);

	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(sf::Color::White);

	Window::getWindow().draw(shape);
}

void Render::renderCount()
{
	static sf::Font font;
	static bool fontL;
	if (!fontL)
	{
		if (font.loadFromFile("C:/Users/MKA/source/repos/Tetris/src/game/core/arial.ttf"));
	}
	sf::Text text;
	text.setFont(font);
	text.setString(std::to_string(count));
	text.setCharacterSize(25);
	text.setPosition(800, 500);

	sf::RenderWindow& window = Window::getWindow();
	window.draw(text);
}

void Render::setCount(int count_) { count = count_; }

void Render::addCount(int count_) { count += count_; }

void Render::update()
{	
	Window::clear();

	Render::renderBorder();

	Render::renderField();

	Render::renderCount();

	Window::display();
}