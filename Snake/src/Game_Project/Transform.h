#pragma once
#include <SDL/SDL.h>

// Transform structure to store Game Objects (and UI Objects) position
struct Transform {
	union {
		SDL_Rect rect;
		struct { Sint32 x, y, w, h; };
	};
	Transform(int x_, int y_) : x(x_), y(y_), w(0), h(0) {}; //constructor, inicializacion de las variables a los parametros pasados
	Transform(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) {}; //constructor 2,inicializacion de las variables a los parametros pasados
	Transform() { x = y = w = h = 0; }; //contructor default, inicializacion de las variables a 0
	//sobrecarga de operadores
	inline const SDL_Rect &operator()(void) const { return rect; };
	friend bool operator==(Transform &lhs, Transform &rhs) {
		return (lhs.x == rhs.x &&
			lhs.y == rhs.y &&
			lhs.w == rhs.w &&
			lhs.h == rhs.h);
	};
};