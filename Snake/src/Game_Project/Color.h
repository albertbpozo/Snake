#pragma once

#include <SDL/SDL.h>
struct Color {//idk como va el tema color tt
	union {
		SDL_Color col;
		struct { Uint8 r, g, b, a; };
	};
	Color(int r_, int g_, int b_, int a_ = 255) : r(r_), g(g_), b(b_), a(a_) {};
	Color(int c) { r = g = b = a = c; };
	Color() { r = g = b = a = 0; };
	//sobrecargas operadores?
	inline const SDL_Color &operator()(void) const { return col; };
	operator bool(void) const { return (r || g || b || a); };
	friend bool operator==(Color &lhs, Color &rhs) { //sobrecarga operador ==
		return (lhs.r == rhs.r &&
			lhs.g == rhs.g &&
			lhs.b == rhs.b &&
			lhs.a == rhs.a);
	};
};