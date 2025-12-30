#pragma once

class GameLogic
{
public:
	static bool fallLogic();

	static void start();

	static void moveRight();

	static void moveLeft();

	static int clearFullLines();

private:
	
	static bool testMove(int y, int x);
};