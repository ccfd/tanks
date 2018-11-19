CXXFLAGS += -std=c++0x

all: main

players.txt : main
	@test -f "main"
	@./main players >$@ 2>/dev/null

include dep.mk

dep.mk : dep.sh src/* src/*/*
	@./dep.sh

main : $(SOURCE:.cpp=.o)
	$(CXX) -o $@ $^ -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


