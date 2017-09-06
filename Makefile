Game: main.o Tile.o Entity.o Room.o
	g++ -std=c++11 -g -Wall main.o Entity.o Tile.o -o Game
main.o: main.cpp Tile.h Entity.h
	g++ -std=c++11 -g -Wall -c main.cpp
Tile.o: Tile.cpp Tile.h
	g++ -std=c++11 -g -Wall -c Tile.cpp
Entity.o: Entity.cpp Entity.h Tile.h
	g++ -std=c++11 -g -Wall -c Entity.cpp
Room.o: Room.cpp Room.h
	g++ -std=c++11 -g -Wall -c Room.cpp
Map.o: Map.cpp Map.h
	g++ -std=c++11 -g -Wall -c Map.cpp
clean:
	rm *.o Game
	echo clean done
