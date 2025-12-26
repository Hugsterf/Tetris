#include "render.h"
#include "field.h"
#include "config.h"
#include "window.h"
#include "../../logger/log.h"
#include "forms.h"

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

void Render::exitProgram()
{
	sf::Event event;
	while (Window::pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			Window::close();
			LOG_ERROR("Окно закрыто!");
		}
	}
}

void Render::update() {}

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

void Render::renderAll()
{	
	Window::clear();

	Render::renderBorder();
	Render::renderField();

	Window::display();
}