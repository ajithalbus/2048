play : main.o state.o utils.o game.o
	g++ -o play main.o state.o utils.o game.o -lncurses

main.o : main.cpp
	g++ -c main.cpp

state.o : state.cpp state.h
	g++ -c state.cpp

utils.o : utils.cpp utils.h
	g++ -c utils.cpp

game.o : game.cpp game.h
	g++ -c game.cpp

clean : 
	rm *.o play
