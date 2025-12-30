#pragma once

class Render
{
public:
	static void renderField();

	static void renderBorder();

	static void pollEvent();

	static void update();

	static void renderCount();

	static void setCount(int count_);

	static void addCount(int count_);

private:
	static int count;
};