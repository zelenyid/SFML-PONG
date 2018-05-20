CC = g++ -std=c++11
CFLAGS = -c
LDFLAGS = -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

all: Pong

Pong: bat.o ball.o menu.o game.o main.o
	$(CC) bat.o ball.o menu.o game.o main.o -o Pong $(LDFLAGS)

bat.o: bat.cpp
	$(CC) $(CFLAGS) bat.cpp

ball.o: ball.cpp
	$(CC) $(CFLAGS) ball.cpp

menu.o: menu.cpp
	$(CC) $(CFLAGS) menu.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.o Pong
