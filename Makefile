CC = g++
CFLAGS = -std=c++11
EXEC_NAME = game
INCLUDES =
LIBS =
OBJ_FILES = Card.o CardValue.o Color.o ComputerPlayer.o Contract.o Deal.o Game.o HumanPlayer.o main.o misc.o Player.o Team.o Trick.o
INSTALL_DIR = ./

all : $(EXEC_NAME)

clean :
	rm *.o
	rm $(EXEC_NAME)


$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

CardValue.o: CardValue.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

Color.o: Color.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)
