objects = main.cpp ballSim.cpp textureManager.cpp ball.cpp

all:
	g++ -Isrc/include -Lsrc\lib -o main $(objects) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image