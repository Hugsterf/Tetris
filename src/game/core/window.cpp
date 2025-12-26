#include "window.h"
#include "config.h"

sf::RenderWindow Window::window;

void Window::initializ()
{
	window.create(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), Config::TITLE);
	window.setFramerateLimit(60);
}

sf::RenderWindow& Window::getWindow() { return window; }

bool Window::pollEvent(sf::Event& event) { return window.pollEvent(event); }

void Window::clear(const sf::Color& color) { window.clear(color); }

void Window::display() { window.display(); }

void Window::close() { window.close(); }

bool Window::isOpen() { return window.isOpen(); }