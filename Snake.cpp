#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "Snake.h"

using namespace std;

bool SnakeGame::getGameState() {
	return gameOver;
}

void SnakeGame::setGameState(bool state) {
	gameOver = state;
}
void SnakeGame::Setup() {

	srand(time(NULL));


	fruitX = (rand() % (width - 2)) + 1;
	fruitY = (rand() % (height - 2)) + 1;
	snakeXPos = width / 10 + 1;
	snakeYPos = height / 2;

	while (snakeYPos == fruitY || snakeXPos == fruitX) {
		fruitX = (rand() % (width - 2)) + 1;
		fruitY = (rand() % (height - 2)) + 1;

	}

}

void SnakeGame::Draw() {
	int i, j, k;

	bool tailPrint;
	for (i = 0; i < height; i++) {

		for (j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				cout << "#";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else if (i == snakeYPos && j == snakeXPos)
				cout << "O";

			else {

				tailPrint = false;

				for (k = 0; k < tailLength; k++) {
					if (i == prevYPos[k] && j == prevXPos[k]) {
						cout << "o";
						tailPrint = true;
					}

				}

				if (!tailPrint)
					cout << " ";


			}

		}
		cout << endl;

	}

	cout << "Score: " << score;


	cout.rdbuf()->pubsetbuf(outputbuf, sizeof(outputbuf));
	ios::sync_with_stdio(false);
}

void SnakeGame::Input() {

	int i, k;
	int currentDir = 0;
	char ch;


	for (i = 0; i < tailLength; i++) {
		k = tailLength - i - 1;

		prevXPos[k + 1] = prevXPos[k];
		prevYPos[k + 1] = prevYPos[k];
	}

	/*
	While user does not change direction
		Increment in current direction
		Check to see if user changes direction
	Endwhile
	*/

	prevXPos[0] = snakeXPos;
	prevYPos[0] = snakeYPos;
	ch = _getch();


	switch (ch) {

		case 'w':
			snakeYPos--;
			break;
		case 's':
			snakeYPos++;
			break;
		case 'a':
			snakeXPos--;
			break;
		case 'd':
			snakeXPos++;
			break;
	}





}

void SnakeGame::GamePlay() {
	int i;

	int length = tailLength;

	if (snakeXPos == fruitX && snakeYPos == fruitY) {

		++tailLength;
		length = tailLength;
		fruitX = (rand() % (width - 2)) + 1;
		fruitY = (rand() % (height - 2)) + 1;


		score += 10;

	}

	if (snakeXPos >= width - 1 || snakeYPos >= height - 1 || snakeXPos == 0 || snakeYPos == 0) {
		setGameState(true);
	}
	for (i = 1; i < length; i++) {
		if (snakeXPos == prevXPos[i] && snakeYPos == prevYPos[i]) {
			setGameState(true);
		}
	}

}