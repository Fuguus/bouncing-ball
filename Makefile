linkTarget = main

LIBS = -lSDL2

CFLAGS = -std=c++17

objects = main.o

rebuildables = $(objects) $(linkTarget)

$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

.PHONEY:
clean:
	rm $(rebuildables)