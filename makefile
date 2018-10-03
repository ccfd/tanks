
main : main.o App.o Bullet.o Globals.o LiveTank.o Object.o TankAvatar.o Player.o TankControl.o KeyboardPlayer.o Obstacle.o Bots/SimpleBot.o
	g++ -o $@ $^ -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio


%.o : %.cpp
	g++ -std=c++0x -c -o $@ $<


## DEP
./main.cpp : ./App.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./LiveTank.h : ./Object.h ./TankAvatar.h ./Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./LiveTank.cpp : ./LiveTank.h ./App.h ./Bullet.h ./TankControl.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Player.h : ./TankControl.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./TankControl.cpp : ./TankControl.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./TankAvatar.cpp : ./Globals.h ./TankAvatar.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Globals.cpp : ./Globals.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./App.cpp : ./App.h ./LiveTank.h ./Bullet.h ./KeyboardPlayer.h ./Obstacle.h ./SimpleBot/SimpleBot.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./KeyboardPlayer.h : ./Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
# ./TankAvatar.h
./Bullet.cpp : ./Bullet.h ./App.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./SimpleBot/SimpleBot.h : ./SimpleBot/../Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./SimpleBot/SimpleBot.cpp : ./SimpleBot/SimpleBot.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Object.h : ./Globals.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Obstacle.h : ./Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Object.cpp : ./Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
# ./TankControl.h
./App.h : ./Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Obstacle.cpp : ./Obstacle.h ./App.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Player.cpp : ./Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./Bullet.h : ./Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
# ./Globals.h
./KeyboardPlayer.cpp : ./KeyboardPlayer.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
