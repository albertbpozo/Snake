#pragma once
#include "Scene.h"
#include "Sprites.h"

class MainMenu : public Scene
{
public: //decalaracion de cabeceras
	explicit MainMenu();
	~MainMenu() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:
	Sprite background; 
	Sprite title;
	Sprite play;
	Sprite exit;

};