#include "Apple.h"
#include "ID.h"
#include "InputManager.h"
#include "TimeManager.h"
#include <time.h>
#include "Logger.h"
#include "Tabla.h"

using namespace Logger;


Apple::Apple() {
	initialized = false;
	contador = 0;
	numMan = 0;
	laManzana.objectID = ObjectID::S_10;
	laManzana.transform = { laManzana.transform.x - laManzana.transform.w , laManzana.transform.y , W.GetWidth() / 40, W.GetHeight() / 40 };
	laManzana.transform.w = 60;
	laManzana.transform.h = 40;

}

posX = rand() % aTabla->numC;
posY = rand() % aTabla->numR;

std::cout << "numC  -- " << aTabla->numC;
std::cout << "numR  -- " << aTabla->numR;

if (posY == 0) {
	posY++;
}

if (posX == 0) {
	posX++;
}
if (posX == aTabla->numC) {
	posX--;
}
if (posY == aTabla->numR) {
	posY--;
}

if (posX > aTabla->numC) {
	posX -= 4;
}



laManzana.transform.x = aTabla->sprites[posX][posY].transform.x;
laManzana.transform.y = aTabla->sprites[posX][posY].transform.y;

std::cout << "Manzana pos Tabla:  X  " << posX << "  Y:  " << posY << std::endl;



Apple::~Apple() {
}

void Apple::Draw() {
	laManzana.Draw();
}



void Apple::Update() {
	//laManzana.transform = laScene.tabla[posX][posY].transform;
	//laManzana.transform = aTabla.sprites[posX][posY].transform;
}

/*void Apple::InitialPos(Tabla aTabla) {
	if (!initialized) {
		posX = rand() % aTabla.numC;
		posY = rand() % aTabla.numR;

		initialized = true;

		//SetPos(aTabla);//, posX, posY);
	}
}*/

/*
void Apple::SetPos(Tabla aTabla, int i, int j) {
	//	posX = rand() % laScene.numC;
	//	posY = rand() % laScene.numR;
	//posX = i;
	//posY = j;
	//laManzana.transform = aTabla.sprites[posX][posY].transform;
	//cout << "Setting manzanaPos to" << laManzana.transform.x <<","<< laManzana.transform.y <<endl;

}*/

void Apple::SetPos(Tabla* aTabla) {

	posX = rand() % aTabla->numC;
	posY = rand() % aTabla->numR;

	std::cout << "numC  -- " << aTabla->numC;
	std::cout << "numR  -- " << aTabla->numR;

	if (posY == 0) {
		posY++;
	}

	if (posX == 0) {
		posX++;
	}
	if (posX == aTabla->numC) {
		posX--;
	}
	if (posY == aTabla->numR) {
		posY--;
	}

	if (posX > aTabla->numC) {
		posX -= 4;
	}



	laManzana.transform.x = aTabla->sprites[posX][posY].transform.x;
	laManzana.transform.y = aTabla->sprites[posX][posY].transform.y;

	std::cout <<"Manzana pos Tabla:  X  "<< posX <<"  Y:  "<< posY << std::endl;


	//std::cout <<"JODER "<< aTabla->sprites[29][29].transform.x << std::endl;

	//tempX = rand() % ((aTabla->sprites[1][aTabla->numR - 1].transform.x) - (aTabla->sprites[1][1].transform.x));

	//tempY = rand() % ((aTabla->sprites[aTabla->numC - 1][1].transform.y) - (aTabla->sprites[1][1].transform.y));

	//tempX += aTabla->sprites[1][0].transform.x+75;

	//tempY += aTabla->sprites[0][1].transform.y+50;

	//laManzana.transform.x = tempX;
	
	//laManzana.transform.y = tempY;

	//	posX = rand() % laScene.numC;
	//	posY = rand() % laScene.numR;
	//posX = rand() % aTabla.numC;
	//posY = rand() % aTabla.numR;
	//posX = rand() % aNumC;
	//posY = rand() % aNumR;
	//laManzana.transform = aTabla.sprites[posX][posY].transform;
}


/*Apple::Apple() {

}

Apple::Apple(int rows, int columns) {

numR = rows;
numC = columns;

laTabla = new Sprite*[numR];
for (int i = 0; i < numR; i++) laTabla[i] = new Sprite[numC];//por cada numero de filas se añaden el numero de columnas

for (int i = 0; i < numR; i++) {
for (int j = 0; j < numC; j++) {
laTabla[i][0].transform = { i * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
laTabla[i][numC - 1].transform = { i * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
(numC - 1) * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
laTabla[0][j].transform = { 0 + ((W.GetWidth() / 2 - ((numR / 2) * 20))) ,
j * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
laTabla[numR - 1][j].transform = { (numR - 1) * (20) + ((W.GetWidth() / 2 - ((numR / 2) * 20))),
j * (20) + ((W.GetHeight() / 2 - ((numC / 2) * 20))),50, 50 };
laTabla[i][j].objectID = ObjectID::S_11;
}
}


numApple = 3;
for (int i = 0; i < numApple; i++) {
A.transform = { rand() % (laTabla[0][0].transform.x + laTabla[0][numR-1].transform.x),
rand() % (laTabla[0][0].transform.y + laTabla[0][numR - 1].transform.y), W.GetWidth() / 40, W.GetHeight() / 40 };
A.objectID = ObjectID::S_10;
apple.push_back(A);
}
}
Apple::~Apple() {

}
void Apple::Update() {

}
void Apple::Pop() {

}
void Apple::Draw() {
for (int i = 0; i < apple.size() - 1; i++) {
apple[i].Draw();
}
}*/