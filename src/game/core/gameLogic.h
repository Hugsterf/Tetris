#pragma once

class GameLogic
{
public:
	static bool fallLogic();

	static void start();

	static void moveRight();

	static void moveLeft();

private:
	
	static bool GameLogic::testMove(int y, int x);
};