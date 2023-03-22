Snake Game

This is a basic console-based Snake game developed in C++.


Game Overview

The game consists of a player-controlled snake that moves around a game board 
trying to eat a target without running into walls or its own tail. The snake
can be moved using the arrow keys or the WASD keys. Each time the snake eats 
a target, its length increases and the player's score increases by 1. If the
snake collides with a wall or its own tail, the game ends and the player has 
to restart.


Requirements

1. A C++ compiler, such as Visual Studio or Code::Blocks.
2. The conio.h and Windows.h header files.

Running the Game

-> Clone the repository to your local machine.

-> Open the project in your preferred C++ IDE.

-> Build and run the project.

-> Use the arrow keys or the WASD keys to control the snake.


Code Overview

• The game is divided into several functions, including game_Setup(), 
  main_Menu(), normal_setup(), game_window(), game_input(), and game_program().

• The game_Setup() function initializes some global variables that are used throughout the game.

• The main_Menu() function displays the game's main menu.

• The normal_setup() function initializes the game's variables and sets up the game board.

• The game_window() function draws the game board and updates the score.

• The game_input() function handles player input.

• The game_program() function handles the game's logic, including moving the snake and checking for collisions.


Conclusion

• This game is a simple implementation of the classic Snake game. It can be used as a starting point
for more advanced game development or as a fun project for learning C++.



