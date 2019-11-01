play : main.o state.o utils.o
	g++ -o play main.o state.o utils.o

main.o : main.cpp
	g++ -c main.cpp

state.o : state.cpp state.h
	g++ -c state.cpp

utils.o : utils.cpp utils.h
	g++ -c utils.cpp

clean : 
	rm *.o play
