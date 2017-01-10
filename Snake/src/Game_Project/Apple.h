#include <vector>
#include "Sprites.h"
#include "Tabla.h"


//using namespace std;

class Apple {
public:
	
	Sprite laManzana;

	//vector<Sprite>manzanas;

	Apple(void);
	~Apple();
	void Draw(void);
	void Update(void);
	void SetPos(Tabla*);
	void SetPos(Tabla, int, int);
	void InitialPos(Tabla);
	int numMan;
	int posX;
	int posY;
	int contador;
	bool initialized;
private:

};

