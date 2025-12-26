#pragma once
#include <SFML/Graphics.hpp>

class Window
{
private:
	static sf::RenderWindow window;
public:
	static void initializ();

	static sf::RenderWindow& getWindow();

	static bool pollEvent(sf::Event& event);

	static void clear(const sf::Color& color = sf::Color::Black);

	static void display();

	static void close();

	static bool isOpen();
};