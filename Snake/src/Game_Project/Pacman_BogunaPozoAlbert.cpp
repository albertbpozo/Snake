#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <thread>
#include <mutex>


#define ARRIBA     72      // CONSTANTS AMB LES FLETXES DEL TECLAT
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80
#define ESC        27
#define ENTER      13

int pacmanAntX;
int pacmanAntY;

int backcolor = 0;
int dir = 0;
int direccioPacman;
int x = 39, y = 22;
int anteriorpx, anteriorpy;

long int punts = -5;
int puntuacioVida = 0;
int minus = 0;
int vides = 3;

std::mutex mut;


void setCColor(int color)
{
	static HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color | (backcolor * 0x10 + 0x100));
}

int color[7] = {
0x009,
0x00E,
0x00C,
0x002,
0x00B,
0x005,
0x00F
};

struct fantasma {
	int fdir; //direcció del fantasma que pot prendre valors del 0-3 i pot ser inicialitzat rand() % 4
	int _x, _y; // posicíó del fantasma
	int col; //color del fantasma
};

void gotoxy(int x, int y)  // funcio que posiciona el cursor a la coordenada (x,y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

char mapa[50][100] = {
"                                                      ",
"                  AXXXXXXXXXXXXXXXXXXXB AXXXXXXXXXXXXXXXXXXXB",
"                  Y___________________Y Y___________________Y",
"                  Y_AXXXXXB_AXXXXXXXB_Y Y_AXXXXXXXB_AXXXXXB_Y",
"                  Y_Y     Y_Y       Y_Y Y_Y       Y_Y     Y_Y",
"                  Y_DXXXXXC_DXXXXXXXC_DXC_DXXXXXXXC_DXXXXXC_Y",
"                  Y________|_________|___|_________|________Y",
"                  Y_AXXXXXB_AXB_AXXXXXXXXXXXXXB_AXB_AXXXXXB_Y",
"                  Y_DXXXXXC_Y Y_DXXXXB   AXXXXC_Y Y_DXXXXXC_Y",
"                  Y_________Y Y______Y   Y______Y Y_________Y",
"                  DXXXXXXXB_Y DXXXXB_Y   Y_AXXXXC Y_AXXXXXXXC",
"                          Y_Y AXXXXC_DXXXC_DXXXXB Y_Y        ",
"                          Y_Y Y_________________Y Y_Y        ",
"                  XXXXXXXXC_DXC_AXXXXXX XXXXXXB_DXC_DXXXXXXXX",
"                  _________|____Y      *      Y____|_________",
"                  XXXXXXXXB_AXB_DXXXXXXXXXXXXXC_AXB_AXXXXXXXX",
"                          Y_Y Y_________________Y Y_Y        ",
"                          Y_Y Y_AXXXXXXXXXXXXXB_Y Y_Y        ",
"                  AXXXXXXXC_DXC_DXXXXB   AXXXXC_DXC_DXXXXXXXB",
"                  Y________|_________Y   Y_________|________Y",
"                  Y_AXXXXXB_AXXXXXXB_Y   Y_AXXXXXXB_AXXXXXB_Y",
"                  Y_DXXXB Y_DXXXXXXC_DXXXC_DXXXXXXC_Y AXXXC_Y",
"                  Y_____Y Y_________|_____|_________Y Y_____Y",
"                  DXXXB_Y Y_AXB_AXXXXXXXXXXXXXB_AXB_Y Y_AXXXC",
"                  AXXXC_DXC_Y Y_DXXXXB   AXXXXC_Y Y_DXC_DXXXB",
"                  Y_________Y Y______Y   Y______Y Y_________Y",
"                  Y_AXXXXXXXC DXXXXB_Y   Y_AXXXXC DXXXXXXXB_Y",
"                  Y_DXXXXXXXXXXXXXXC_DXXXC_DXXXXXXXXXXXXXXC_Y",
"                  Y_________________|_____|_________________Y",
"                  DXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXC",
};


void pintar_mapa()// Funcio que imprimeix el mapa basant-se en el mapa codificat
{
	for (int i = 0; i < 78; i++) {
		for (int j = 0; j < 30; j++) {
			gotoxy(i, j);

			if (mapa[j][i] == 'X') {
				setCColor(color[0]);
				printf("%c", 205);
			}
			if (mapa[j][i] == '_') {
				setCColor(color[0]);
				printf("%c", 250);
			}
			else if (mapa[j][i] == 'Y') {
				setCColor(color[0]);
				printf("%c", 186);
			}
			else if (mapa[j][i] == 'A') {
				setCColor(color[0]);
				printf("%c", 201);
			}
			else if (mapa[j][i] == 'B') {
				setCColor(color[0]);
				printf("%c", 187);
			}
			else if (mapa[j][i] == 'C') {
				setCColor(color[0]);
				printf("%c", 188);
			}
			else if (mapa[j][i] == 'D') {
				setCColor(color[0]);
				printf("%c", 200);
			}


		}
	}
}

void tecleig() {
	if (_kbhit()) {
		char tecla = _getch();
		switch (tecla) {
		case ARRIBA:
			dir = 0;
			break;

		case ABAJO:
			dir = 1;
			break;

		case DERECHA:
			dir = 2;
			break;

		case IZQUIERDA:
			dir = 3;
			break;
		}
	}

}



void pintarPacman(int x, int y) {
	//TODO seleccionar color (funció)
	//TODO anar a la posicio indicada (funció)
	//TODO imprimir el caracter amb codi ASCII 6
	setCColor(color[1]);	
	gotoxy(x, y);	
	printf("%c", 6);
}

void borrarPacman(int x, int y) {
	//TODO anar a la posicio indicada (funció)
	//TODO imprimir el caracter d'espai
	gotoxy(x, y);	
	printf("%c", 32);
	if (mapa[y][x] == '_')
	{
		mapa[y][x] = 32;
		punts += 5;

		if (puntuacioVida != 25)
		{
			puntuacioVida += 5;

			if (puntuacioVida == 25)
			{
				if (vides < 3) vides++;
				puntuacioVida = 0;
			}
		}
	}
}

void direccioPac()
{
	if (direccioPacman == 0) y = y - 1;
	else if (direccioPacman == 1) y = y + 1;
	else if (direccioPacman == 2) x = x + 1;
	else if (direccioPacman == 3) x = x - 1;
}

void mourePacman()
{
	//TODO guardar la posició anterior del pacman
	//TODO detectar cap a on moure pacman
	//TODO comprovar si es pot moure en aquesta direcció
	//TODO esborrar el pacman de l'anterior posició i imprimir-lo en la nova
	//Guardem posicio
	pacmanAntX = x;
	pacmanAntY = y;

	tecleig();
	//detectar capa  on moure pacman
	//comprovar so es pot moure en aquesta direccio
	
	if (mapa[y][x] == '_' || mapa[y][x] == '|' || mapa[y][x] == ' ')
	{
		if (dir == 0 && mapa[y - 1][x] != 'X' && mapa[y - 1][x] != 'Y' && mapa[y - 1][x] != 'A' && mapa[y - 1][x] != 'B' && mapa[y - 1][x] != 'C' && mapa[y - 1][x] != 'D')
			direccioPacman = dir;
		else if (dir == 1 && mapa[y + 1][x] != 'X' && mapa[y + 1][x] != 'Y' && mapa[y + 1][x] != 'A' && mapa[y + 1][x] != 'B' && mapa[y + 1][x] != 'C' && mapa[y + 1][x] != 'D')
			direccioPacman = dir;
		else if (dir == 2 && mapa[y][x + 1] != 'X' && mapa[y][x + 1] != 'Y' && mapa[y][x + 1] != 'A' && mapa[y][x + 1] != 'B' && mapa[y][x + 1] != 'C' && mapa[y][x + 1] != 'D')
			direccioPacman = dir;
		else if (dir == 3 && mapa[y][x - 1] != 'X' && mapa[y][x - 1] != 'Y' && mapa[y][x - 1] != 'A' && mapa[y][x - 1] != 'B' && mapa[y][x - 1] != 'C' && mapa[y][x - 1] != 'D')
			direccioPacman = dir;

		direccioPac();
	}

	if (mapa[y][x] == 'X' || mapa[y][x] == 'Y' || mapa[y][x] == 'A' || mapa[y][x] == 'B' || mapa[y][x] == 'C' || mapa[y][x] == 'D')
	{
		x = pacmanAntX;
		y = pacmanAntY;
	}

	if (x > 60) x = 18;
	else if (x < 18) x = 60;

	
	mut.lock();
	borrarPacman(pacmanAntX, pacmanAntY);
	pintarPacman(x, y);
	mut.unlock();
}

fantasma inicialitzarFantasma(int x, int y, int color, int direccio) {
	//TODO inicialitzar el fantasma amb les dades donades i la direcció rand() % 4
	srand(time(NULL));
	fantasma monster;
	monster.fdir = direccio;
	monster._x = x;
	monster._y = y;
	monster.col = color;

	return monster;
}

void pintarFantasma(fantasma ghost) {
	//TODO seleccionar color (funció)
	//TODO anar a la posicio indicada (funció)
	//TODO imprimir el caracter amb codi ASCII 6
	setCColor(ghost.col);
	gotoxy(ghost._x, ghost._y);
	printf("%c", 6);
}
void borrarFantasma(fantasma ghost) {

	//TODO anar a la posicio indicada (funció)
	//TODO imprimir el caracter d'espai
	gotoxy(ghost._x, ghost._y);
	printf("%c", 32);

}
void xocPacman(fantasma ghost) {
	//TODO detectar si el fantasma colisiona amb l'actual o l'anterior posició del Pacman, de ser aixi posicionar al jugador a x=39, y=22, dir = 4 i disminuir en una les vides
	if ((ghost._x == x && ghost._y == y) || (ghost._x == pacmanAntX && ghost._y == pacmanAntY))
	{
		vides--;
		x = 39;
		y = 22;
		dir = 0;
		minus++;
		punts -= 25;
		pintarPacman(x, y);
	}
}

void movimFant(fantasma &ghost, int _bolx, int _boly)
{
	std::vector<int> paths;
	ghost._x = _bolx;
	ghost._y = _boly;

	if ((mapa[_boly + 1][_bolx] == '_' || mapa[_boly + 1][_bolx] == ' ') && ghost.fdir != 0)
	{
		paths.push_back(1);
	}

	if ((mapa[_boly - 1][_bolx] == '_' || mapa[_boly - 1][_bolx] == ' ') && ghost.fdir != 1)
	{
		paths.push_back(0);
	}

	if ((mapa[ghost._y][_bolx - 1] == '_' || mapa[ghost._y][_bolx - 1] == ' ') && ghost.fdir != 2)
	{
		paths.push_back(3);
	}

	if ((mapa[ghost._y][_bolx + 1] == '_' || mapa[ghost._y][_bolx + 1] == ' ') && ghost.fdir != 3)
	{
		paths.push_back(2);
	}

	int newPath = rand() % paths.size();
	newPath = paths[newPath];

	ghost.fdir = newPath;

	if (ghost.fdir == 3) {
		ghost._x--;
	}
	else if (ghost.fdir == 2)
	{
		ghost._x++;
	}
	else if (ghost.fdir == 1)
	{
		ghost._y++;
	}
	else if (ghost.fdir == 0)
	{
		ghost._y--;
	}
}

void moureFantasma(fantasma &ghost) {
	//TODO Esborrar el fantasma
	//TODO intentar seguir en la direcció que anava, en cas de trobar-se amb algun obstacle (X,A,B,C,D) intentar-lo redirigir
	//TODO Printar el fantasma

	srand(time(NULL));
	int bolx = ghost._x, boly = ghost._y;


	if (mapa[ghost._y][ghost._x] == '*') {
		ghost.fdir = 0;
	}

	if (mapa[ghost._y][ghost._x] == '|') {
		mut.lock();
		borrarFantasma(ghost);
		mut.unlock();
		movimFant(ghost, ghost._x, ghost._y);
	}

	else
	{
		//TODO Esborrar el fantasma
		mut.lock();
		borrarFantasma(ghost);
		mut.unlock();

		//TODO intentar seguir en la direcció que anava, en cas de trobar-se amb algun obstacle (X,A,B,C,D) intentar-lo redirigir
		if (ghost.fdir == 3) {
			ghost._x--;
		}
		else if (ghost.fdir == 2)
		{
			ghost._x++;
		}
		else if (ghost.fdir == 1)
		{
			ghost._y++;
		}
		else if (ghost.fdir == 0)
		{
			ghost._y--;
		}
	}

	if (mapa[ghost._y][ghost._x] == 'X' || mapa[ghost._y][ghost._x] == 'Y')
	{
	movimFant(ghost, bolx, boly);
	}

	if (ghost._x > 60) ghost._x = 18;
	else if (ghost._x < 18) ghost._x = 60;

	//TODO Printar el fantasma
	mut.lock();
	pintarFantasma(ghost);

	if (mapa[boly][bolx] == '_') {
		setCColor(color[1]);
		gotoxy(bolx, boly);
		printf("%c", 250);
	}
	mut.unlock();
}


void marcador() {

	while (vides > 0 && punts < 1950 - (25 * minus))
	{
		setCColor(color[3]);
		mut.lock();
		gotoxy(5, 4); printf("PUNTUACION");
		gotoxy(5, 6); printf("    ");
		mut.unlock();
		setCColor(color[6]);
		mut.lock();
		gotoxy(5, 6); printf("%ld", punts);
		mut.unlock();
		setCColor(color[1]);
		mut.lock();
		gotoxy(5, 25); printf("VIDAS");

		for (int i = 0; i <= vides; i++) {
			gotoxy(5, i + 27); printf(" ");

		}
		for (int i = 0; i < vides; i++) {
			gotoxy(5, i + 27); printf("%c", 2);

		}

		mut.unlock();
		setCColor(color[2]);
		mut.lock();
		gotoxy(70, 27); printf("%c", 169);
		mut.unlock();
	}


}

void gamePacman()
{
	while (vides > 0 && punts < 1950 - (25 * minus))
	{
		mourePacman();

		std::this_thread::sleep_for(std::chrono::milliseconds(110));
	}
}

void gameGhosts(fantasma ghost)
{
	while (vides > 0 && punts < 1950 - (25 * minus))
	{
		moureFantasma(ghost);
		xocPacman(ghost);

		std::this_thread::sleep_for(std::chrono::milliseconds(110));
	}
}

int main() {


	HWND cmd = GetConsoleWindow();
	RECT dim;
	GetWindowRect(cmd, &dim);
	MoveWindow(cmd, dim.left, dim.top, 700, 600, TRUE);
	fantasma ghostA = inicialitzarFantasma(41, 14, 2,3);
	fantasma ghostB = inicialitzarFantasma(43, 14, 3,3);
	fantasma ghostC = inicialitzarFantasma(40, 14, 4,3);
	fantasma ghostD = inicialitzarFantasma(39, 14, 5,3);
	pintar_mapa();
	pintarPacman(x, y);
	pintarFantasma(ghostA);
	pintarFantasma(ghostB);
	pintarFantasma(ghostC);
	pintarFantasma(ghostD);

	std::thread threadMarcador([&] {marcador(); });
	std::thread threadMourePacman([&] {gamePacman(); });
	std::thread threadGhostA([&] {gameGhosts(ghostA); });
	std::thread threadGhostB([&] {gameGhosts(ghostB); });
	std::thread threadGhostC([&] {gameGhosts(ghostC); });
	std::thread threadGhostD([&] {gameGhosts(ghostD); });

	threadMarcador.join();
	threadMourePacman.join();
	threadGhostA.join();
	threadGhostB.join();
	threadGhostC.join();
	threadGhostD.join();
	for (int i = 0; i <= vides; i++) {
		gotoxy(5, i + 27);
		printf(" ");
	}

	system("pause>NULL");
	return 0;

}
