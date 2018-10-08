all: main

include dep.mk

dep.mk : dep.sh src/* src/*/*
	@./dep.sh

main : $(SOURCE:.cpp=.o)
	g++ -o $@ $^ -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

%.o : %.cpp
	g++ -std=c++0x -c -o $@ $<


