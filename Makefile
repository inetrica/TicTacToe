CC = g++
CFLAGS = -Wall -Werror
STD = -std=c++11
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -pthread
INCLUDE = -I./head
SDIR = src
ODIR = obj
OBJFILES = Main.o Game.o Board.o Block.o Textures.o
OBJS = $(patsubst %, $(ODIR)/%, $(OBJFILES))
EXE = ttt

.Phony: depend clean

all: $(EXE) 

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $^ $(LFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) $(STD) $(INCLUDE) -c $< -o $@

clean:
	rm $(ODIR)/*.o $(EXE)
