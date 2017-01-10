#include "Snake.h"
#include "GameScene.h"


GameScene::GameScene() {
	start = false;
}

GameScene::~GameScene() {
}

void GameScene::OnEntry(void) {
	if (!start) {
		columnas = Niveles::GetValue("columns");
		filas = Niveles::GetValue("rows");
		drawGrid.CreateTable(columnas, filas);
		start = true;
		int tempNum = round(columnas / 2);
		int tempNum2 = round(filas / 2);
		snake.InitialPos(tempNum * 30, tempNum2 * 30);
	}
}

void GameScene::OnExit(void) {

}

void GameScene::Update(void) {
	snake.Move();
	snake.Die(columnas, filas);
}

void GameScene::Draw(void) {
	if (start) {
		drawGrid.Draw();
		snake.Draw();
	}
}
