
main : main.o App.o Bullet.o Globals.o LiveTank.o Object.o TankAvatar.o
	g++ -o $@ $^ -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio


%.o : %.cpp
	g++ -c -o $@ $<


