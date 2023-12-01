CC=g++ -g
EXE_FILE=application

all: $(EXE_FILE)

$(EXE_FILE): main.o bats.o event.o game.o gold.o stalicites.o room.o wumpus.o  
	$(CC) main.o bats.o event.o game.o gold.o stalicites.o room.o wumpus.o -o $(EXE_FILE)

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

event.o: event.h event.cpp
	$(CC) -c event.cpp

game.o: game.h game.cpp
	$(CC) -c game.cpp

gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp

stalicites.o: stalicites.h stalicites.cpp
	$(CC) -c stalicites.cpp

room.o: room.h room.cpp
	$(CC) -c room.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp

clean:
	rm -f *.o $(EXE_FILE)