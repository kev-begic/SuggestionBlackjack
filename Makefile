CC = g++
LD = g++

CFLAGS = -c -pedantic-errors -std=c++14 -Wall -fno-elide-constructors
LFLAGS = -pedantic-errors -Wall

OBJS = blackjack.o Book.o Dealer.o Game.o Player.o Utility.o
PROG = blackjack.exe

default: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $(PROG)

blackjack.o: blackjack.cpp Game.h
	$(CC) $(CFLAGS) blackjack.cpp

Book.o: Book.cpp Book.h Utility.h
	$(CC) $(CFLAGS) Book.cpp

Dealer.o: Dealer.cpp Dealer.h Utility.h
	$(CC) $(CFLAGS) Dealer.cpp

Game.o: Game.cpp Game.h Utility.h Dealer.h Player.h Book.h
	$(CC) $(CFLAGS) Game.cpp

Player.o: Player.cpp Player.h Utility.h
	$(CC) $(CFLAGS) Player.cpp

Utility.o: Utility.cpp Utility.h
	$(CC) $(CFLAGS) Utility.cpp

clean:
	rm -f *.o

real_clean:
	rm -f *.o
	rm -f *exe