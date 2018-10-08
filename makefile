
main : ./src/main.o ./src/App.o ./src/Bullet.o ./src/Globals.o ./src/LiveTank.o ./src/Object.o ./src/TankAvatar.o ./src/Player.o ./src/TankControl.o ./src/KeyboardPlayer.o ./src/Obstacle.o ./src/SimpleBot/SimpleBot.o
	g++ -o $@ $^ -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio


%.o : %.cpp
	g++ -std=c++0x -c -o $@ $<


## DEP
./src/KeyboardPlayer.h : ./src/Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/LiveTank.cpp : ./src/LiveTank.h ./src/App.h ./src/Bullet.h ./src/TankControl.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/Bullet.h : ./src/Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/Obstacle.cpp : ./src/Obstacle.h ./src/App.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/Globals.cpp : ./src/Globals.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
# ./src/TankAvatar.h
./src/Bullet.cpp : ./src/Bullet.h ./src/App.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
# ./src/Globals.h
./src/App.cpp : ./src/App.h ./src/LiveTank.h ./src/Bullet.h ./src/Obstacle.h ./src/Factory.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/Object.cpp : ./src/Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/LiveTank.h : ./src/Object.h ./src/TankAvatar.h ./src/Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/App.h : ./src/Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/main.cpp : ./src/App.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/TankAvatar.cpp : ./src/Globals.h ./src/TankAvatar.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/Obstacle.h : ./src/Object.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/Player.h : ./src/TankControl.h ./src/Factory.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/TankControl.cpp : ./src/TankControl.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
# ./src/Factory.h
./src/SimpleBot/SimpleBot.h : ./src/SimpleBot/../Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/SimpleBot/SimpleBot.cpp : ./src/SimpleBot/SimpleBot.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
# ./src/TankControl.h
./src/Object.h : ./src/Globals.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/Player.cpp : ./src/Player.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
./src/KeyboardPlayer.cpp : ./src/KeyboardPlayer.h
	@test -f $@ && touch $@
	@echo $@ depends on $^
