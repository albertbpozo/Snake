#pragma once
#include "Scene.h"
#include "Sprites.h"
#include <vector>

class Niveles : public Scene
{
public:
	explicit Niveles(); 
	~Niveles() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
	int static GetValue(std::string valor);



private:
	Sprite background;
	Sprite title;
	Sprite easy;
	Sprite medium;
	Sprite hard;

};