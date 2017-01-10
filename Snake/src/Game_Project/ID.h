#pragma once
#include <iostream>

enum class ObjectID : const int { //enum de los distintos ids del juego
	S_00, //background
	S_01, //Titulo
	S_02, // play
	S_03, //Easy
	S_04, //Med
	S_05, //hard
	S_06, //exit
	S_07, //bg niveles
	S_08, //cabeza serpiente
	S_09, //cuerpo
	S_10, // cola -- MANZANA
	S_11, // apple
	S_12 //pared
	 
	
};
inline std::ostream &operator<<(std::ostream &os, const ObjectID &id) { return os << int(id); }; //sobre carga ooperador <<
inline std::istream &operator>>(std::istream &is, ObjectID &id) { return is >> reinterpret_cast<int&>(id); }; //sobrecarga operador >>