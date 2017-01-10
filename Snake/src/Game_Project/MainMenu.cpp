#include "MainMenu.h"
#include "Niveles.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


MainMenu::MainMenu() { //constructor, inicializamos la posicion de cada uno de los sprites mencionados y le asignamos su imagen
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::S_00 };
	title = { { 250, 0, W.GetWidth()/2, W.GetHeight()/2 }, ObjectID::S_01 };
	play = { { 362, 350, W.GetWidth()/3, W.GetHeight()/3 }, ObjectID::S_02 };
	exit = { { 362,550,W.GetWidth()/3, W.GetHeight()/3 }, ObjectID::S_06 };

}
MainMenu::~MainMenu() {
}
void MainMenu::OnEntry(void) {
}
void MainMenu::OnExit(void) {
}
void MainMenu::Update(void) {
	static MouseCoords mouseCoords(0, 0); //variable que se guardara las coordenadas del puntero del raton al hacer click, inizializadas a 0
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) { //si hace clickizquierdo
		mouseCoords = IM.GetMouseCoords();  //se guarda esas coordenadas
		if ((mouseCoords.x >= 425 && mouseCoords.x <= 615) && (mouseCoords.y >= 430 && mouseCoords.y <= 490)) {		//si el click esta entre estas coordenadas, carga escena Niveles
			SM.SetCurScene<Niveles>();		//tenemos intencion de cambiar esto por coord x = -sprite.width/2 y coord y = -sprite.height/2 
		}
		else if ((mouseCoords.x >= 425 && mouseCoords.x <= 615) && (mouseCoords.y >= 630 && mouseCoords.y <= 690)) {
			SetState<SceneState::EXIT>(); //si el clickesta entre estas coordenadas, sale deljuego.
		}
	}

}
void MainMenu::Draw(void) { //metodo que printea los sprites
	background.Draw();
	title.Draw();
	play.Draw();
	exit.Draw();
}