#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

// Intialising the variables
bool normalGame, mainMenu, snakeGame;
const int width = 50;
const int height = 20;


// User variables
int x, y, spd = 1;
int tailX[100], tailY[100], taillength;

// Tail Coordinates
int fposX, fposY, sposX, sposY;

// Target variables
int targetX, targetY;
int score;  

// Directions variable
enum directions { STOP = 0, UP, DOWN, LEFT, RIGHT };
directions dir;

void game_Over() {
	normalGame = false;
	mainMenu = true;
	taillength = 0;
	score = 0;
}

void game_Setup() {
	snakeGame = true;
	mainMenu = true;
}


void main_Menu() {
	system("cls");
	char heart = 3;
	cout << "Hello there !" << endl;
	cout << "Welcome to the Snake Game" << endl;

	cout << endl << endl;
	cout << "---  Instructions ----" << endl;
	cout << "Player can play this game by using 'W A S D'  or by 'ARROW KEYS' " << endl;
	cout << "Press 'Enter' to play the game" << endl << endl;
	cout << "Made with " << heart << " by Raj" << endl;

	if (GetAsyncKeyState(VK_RETURN)) {
		mainMenu = false;
	}
	else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		dir = STOP;
	}
	else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		dir = STOP;
	}
	else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		dir = STOP;
	}
	else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		dir = STOP;
	}
}

void normal_setup() {
	normalGame = true;
	dir = STOP;
	x = rand() % width;
	y = rand() % height;
	targetX = rand() % width;
	targetY = rand() % height;
	// Error when target and player are on top
	 while (x == targetX && y == targetY) {
		x = rand() % width;
		y = rand() % height;
		targetX = rand() % width;
		targetY = rand() % height;
	}
	score = 0;

}


void game_window() {

	system("cls");

	// Top body
	for (int i = 0; i < width; i++) {
		cout << "*";

	}
	cout << endl;

	// Body
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) {
				cout << "*";
			}
			else if (i == y && j == x) {
				cout << "S";
			}
			else if (i == targetY && j == targetX) {
				cout << "O";
			}
			else {
				bool tail = false;
				for (int k = 0; k < taillength; k++) {
					if (j == tailX[k] && i == tailY[k]) {
						cout << "s";
						tail = true;
					}
				}
				if (!tail) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	// Bottom border
	for (int i = 0; i < width; i++) {
		cout << "*";

	}
	cout << endl << endl;
	cout << "SCORE : " << score;
	// cout << endl << endl << endl;

}

void game_input() {

	if (mainMenu == false && normalGame == true) {

		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A') && dir != RIGHT) {
			dir = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D') && dir != LEFT) {
			dir = RIGHT;
		}
		else if (GetAsyncKeyState(VK_DOWN)  || GetAsyncKeyState('S') && dir != UP) {
			dir = DOWN;
		}
		else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W') && dir != DOWN) {
			dir = UP;
		}
		else if (GetAsyncKeyState(VK_RETURN)) {
			return;
		}
	}
	 
	
}

void game_program() {

	// Tail
	fposX = tailX[0];
	fposY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < taillength; i++) {
		sposX = tailX[i];
		sposY = tailY[i];
		tailX[i] = fposX;
		tailY[i] = fposY;
		fposX = sposX;
		fposY = sposY;
	}

	// Move the snake
	switch (dir) {

		case LEFT:
			x -= spd;
			break;
		case UP:
			y -= spd;
			break;
		case DOWN:
			y += spd;
			break;
		case RIGHT:
			x += spd;
			break;
	}
	// Snake border hit
	if (x <= 0 || x >= width - 1 || y < 0 || y > height - 1) {
		game_Over();
	}

	// Snake Tail Hit
	for (int i = 0; i < taillength; i++) {
		if (x == tailX[i] && y == tailY[i]) {
			game_Over();
		}
	}

	// Snake hits the Target
	if (x == targetX && y == targetY) {
		targetX = rand() % width;
		targetY = rand() % height;
		score++;
		taillength++;
	}
}



int main() {

	game_Setup();
	while (snakeGame == true) {

		if (mainMenu == true) {
			main_Menu();
		}
		else if (mainMenu == false) {
			normal_setup();
			while (normalGame == true) {
				game_window();
				game_input();
				game_program();
				Sleep(60);
			}
		}
	}
	return 0;

}