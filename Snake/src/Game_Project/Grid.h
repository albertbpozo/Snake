#pragma once
#include "Sprites.h"
#include "Logger.h"
#include "ID.h"
using namespace Logger;

class Grid {
public:
	int filas;
	int columnas;
	Sprite** grid;
	void Draw();
	Grid();
	void CreateTable(int, int);
	bool wasMade;
};
