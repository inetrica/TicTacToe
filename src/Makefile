CC = g++
CFLAGS = -Wall -Werror
INCLUDE = -I../head
SRC = Main.cpp Board.cpp Block.cpp
OBJ = $(SRC:.cpp=.o)
EXE = ttt

.Phony: depend clean

all: $(EXE) 

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(EXE) $(OBJ)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm *.o *~ $(EXE)

depend: $(SRC)
	makedepend $(INCLUDE) $^

# for makedepend ?
