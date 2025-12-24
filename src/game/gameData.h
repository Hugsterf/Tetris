#pragma once
#include <iostream>

class fieldData
{
private:
	int** mass;
	size_t size;
public:
	fieldData(const size_t size);

	~fieldData();

	void show() const;
};

class positionData
{
private:
	static int** posXMass;
	static int** posYMass;
	static size_t sizeX;
	static size_t sizeY;

	positionData() = delete;
public:
	static void create(size_t sizeY, size_t sizeX);
	static void destroy();

	static int getXPos(size_t row, size_t col);
	static int getYPos(size_t row, size_t col);

	static size_t getSizeX() { return sizeX; }
	static size_t getSizeY() { return sizeY; }

	static void show();
};