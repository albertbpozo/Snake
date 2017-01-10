#include "GameEngine.h"


// Game constants
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800

int main(int argc, char* args[]) {
	GameEngine::Run<SCREEN_WIDTH, SCREEN_HEIGHT>("Snake");

	return 0;
}