
main : main.o App.o Bullet.o Globals.o LiveTank.o Object.o TankAvatar.o Player.o TankControl.o KeyboardPlayer.o Obstacle.o Bots/SimpleBot.o
	g++ -o $@ $^ -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio


%.o : %.cpp
	g++ -std=c++0x -c -o $@ $<


