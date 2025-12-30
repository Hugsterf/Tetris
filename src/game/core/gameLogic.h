#pragma once

class GameLogic
{
public:
	static bool fallLogic();

	static void start();

	static void moveRight();

	static void moveLeft();

	static int clearFullLines();

	static void resetGame();

private:
	
	static bool testMove(int y, int x);
};