Game: main.o Tile.o Entity.o
	g++ -std=c++11 -g -Wall main.o Entity.o Tile.o -o Game
main.o: main.cpp Tile.h Entity.h
	g++ -std=c++11 -g -Wall -c main.cpp
Tile.o: Tile.cpp Tile.h
	g++ -std=c++11 -g -Wall -c Tile.cpp
Entity.o: Entity.cpp Entity.h Tile.h
	g++ -std=c++11 -g -Wall -c Entity.cpp
clean:
	rm *.o Game
	echo clean done
