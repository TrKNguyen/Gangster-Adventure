# Code SDL Game Phieu Luu - Gangster Adventure
# Author : Tran Khoi Nguyen - 22021118
This is a fun and exciting game that I personally created as a project. It has been designed to be straightforward and easy to play, making it perfect for all ages. The game was created using C++ and relies on SDL 2.0.

Installation Instructions:
To install and enjoy the game on your computer, you will need to ensure that you have the following prerequisites:

GNU C++
SDL 2.0
For Windows users, simply copy SDL 2.0 to the source code folder. For Linux users, please follow the installation tutorials for SDL 2.0, SDL Image, SDL Mixer, and SDL TTF.

Once you have the prerequisites installed, download and extract the source code. Open the command prompt or PowerShell, direct to the folder where you have extracted the code, and type the following command to compile:

If you use the command prompt (cmd), type: make
If you use PowerShell, type: ./make
After the compiling process, check for the existence of the executable file named "GangsterAdventure.exe". Then, to start playing the game, type the following command:

If you use the command prompt (cmd), type: GangsterAdventure
If you use PowerShell, type: ./GangsterAdventure
Enjoy playing GangsterAdventure and have fun!

***The main function of the program consists of several parts:

"init()" function is called to initialize the game, such as setting up the window and loading the necessary assets.

The program enters into a loop with the condition of "while (1)" which means the loop will run infinitely until breakout conditions are met.

The loop first checks if the user has selected an option from the main menu with the "XuLiMenu()" function.

If the user selects to play the game, the "Play()" function is called.

After the game finishes, the "End()" function is called to handle the end of the game.

The program then releases the memory allocated for the game with "GiaiPhongBoNhoPlay()" and "GiaiPhongBoNhoMenu()" functions respectively.

If the user chooses not to play again, the loop breaks and the program exits.

The program ends by calling the "KetThuc()" function to handle any necessary cleanup.

Overall, this code structure ensures that the game initializes properly, runs smoothly, and exits cleanly.

***Function bool start_game

The function checks if the user chooses to play again with "if (ChoiLai == true)" and if so, it returns 1, which means the game should start again.

The function loads the font with the "PhongChuMenu = TTF_OpenFont("font/Pacifico.ttf", 50);" function call, and then a "DongMoDau" text is rendered with the "loadText" function.

An infinite while loop is entered until the user presses the spacebar to start the game or exit the game.

Inside the loop, the rendering of the background, text, and idle image of Pikachu is done using various rendering functions provided by SDL.

A rectangle is rendered on the screen where the spacebar text is displayed, which is used to check whether the spacebar has been pressed using the "SDL_PollEvent" function.

When the spacebar is pressed, a mouse-click sound is played with "Mix_PlayChannel(-1, AnChuot, 0);" and the function returns 1 to signify the game should start.

The function also checks for any quit events by checking "if (e.type == SDL_QUIT)" and returns 0, signifying the user has chosen to exit the game.

Overall, this function ensures that the user can start the game by pressing the spacebar and provides a smooth transition from the start menu to the main game.

***