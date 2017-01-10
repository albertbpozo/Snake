#include "Grid.h"

Grid::Grid() {

	wasMade = false;
	
}
void Grid::CreateTable(int rows, int columns) {

	filas = rows;
	columnas = columns;
	grid = new Sprite*[rows];

	for (int i = 0; i < rows; i++) {
		grid[i] = new Sprite[columns];
	}
	wasMade = true;
}

void Grid::Draw() {
	if (wasMade) {
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				grid[i][j].objectID = ObjectID::S_12;
				grid[i][j].transform = { 30 * i, 30 * j, 30, 30 };
				grid[i][j].Draw();

			}
		}
	}
}