set OBJS=main.cpp Pic.cpp 
set OBJ_NAME=GangsterAdventure.exe
set COMPILER_FLAGS= -w -O2
set LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
set INCLUDE_DIR=-I ".\i686-w64-mingw32\include\SDL2" -L ".\i686-w64-mingw32\lib"

g++ -g %OBJS% %COMPILER_FLAGS% %INCLUDE_DIR% %LINKER_FLAGS% -o %OBJ_NAME%
