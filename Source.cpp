#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "Snake.h"
using namespace std;

int main() {
	SnakeGame startSnake;
	startSnake.setGameState(false);
	startSnake.Setup();

	while (!startSnake.getGameState()) {
		
		startSnake.Draw();
		startSnake.Input();
		
		startSnake.GamePlay();
		Sleep(80);
		system("cls");
		
	}
	
	cout << "GAME OVER";
	return 0;
}