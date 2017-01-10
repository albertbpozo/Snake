#include "Niveles.h"
#include "GameScene.h"
#include "ID.h"
#include "XML.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
#include <vector>
#include <XML/rapidxml_utils.hpp>
using namespace Logger;

static std::vector <int> xmlVal;

Niveles::Niveles() {//constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_00 };
	title = { { 250, 0, W.GetWidth() / 2, W.GetHeight() / 2 }, ObjectID::S_01 };
	easy = { { 400,300,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_03 };
	medium = { { 400,400,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID:: S_04 };
	hard = { { 400,500,W.GetWidth() / 4, W.GetHeight() / 4 }, ObjectID::S_05 };

//	cout<<"notOutOfRange " << xmlVal[0];
}
Niveles::~Niveles() { //destructor
}
int Niveles::GetValue(std::string valor) {
	if (xmlVal.size() > 0) {
		if (valor == "rows") return xmlVal[0];
		else if (valor == "columns") return xmlVal[1];
		else if (valor == "time") return xmlVal[2];
		else if (valor == "speed") return xmlVal[3];
		else if (valor == "initial") return xmlVal[4];
		else if (valor == "incremental") return xmlVal[5];
		else return NULL;
	}
	else return NULL;
}
void Niveles::OnEntry(void) { 
}
void Niveles::OnExit(void) {
}
void Niveles::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) { 
		mouseCoords = IM.GetMouseCoords(); 

		
		if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 360 && mouseCoords.y <= 400)) { 
			XML(1);
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>(); 

		}
		else if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 460 && mouseCoords.y <= 500)) {
			XML(2);
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>();

		}
		else if ((mouseCoords.x >= 450 && mouseCoords.x <= 590) && (mouseCoords.y >= 560 && mouseCoords.y <= 600)) {
			XML(3);
			xmlVal = xmlValues;
			SM.SetCurScene<GameScene>();

		}
	}

}
void Niveles::Draw(void) {
	background.Draw();
	title.Draw();
	easy.Draw();
	medium.Draw();
	hard.Draw();
}

