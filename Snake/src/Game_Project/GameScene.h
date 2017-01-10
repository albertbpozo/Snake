#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Logger.h"
#include "ID.h"
#include "Grid.h"
#include "Snake.h"
#include "math.h"
#include "Niveles.h"

class GameScene : public Scene {

public:
	Grid drawGrid;
	Snake snake;
	int columnas;
	int filas;
	bool start;

	explicit GameScene();
	~GameScene();
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:

};