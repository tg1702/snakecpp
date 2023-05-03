class SnakeGame {
private:
	const int width = 25;
	const int height = 25;
	bool gameOver;
	int snakeXPos, snakeYPos;
	int fruitX, fruitY;
	char tail[200];
	int score = 0;
	int tailLength = 0;
	int prevXPos[200];
	int prevYPos[200];
	char outputbuf[1300];

public:
	bool getGameState();
	void setGameState(bool);
	void Setup();
	void Draw();
	void Input();
	void GamePlay();
};