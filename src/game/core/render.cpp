#include "render.h"
#include "field.h"
#include "config.h"
#include "window.h"
#include "../../logger/log.h"

void Render::renderShapes()
{
	Window::clear();

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

	Window::display();
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