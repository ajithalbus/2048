play : main.o state.o
	g++ -o play main.o state.o

main.o : main.cpp
	g++ -c main.cpp

state.o : state.cpp state.h
	g++ -c state.cpp

clean : 
	rm main.o play
