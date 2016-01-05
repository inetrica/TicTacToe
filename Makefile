CC = g++
CFLAGS = -Wall -Werror
SFML = -lsfml-graphics -lsfml-window -lsfml-system
INCLUDE = -I./head
SDIR = src
ODIR = obj
OBJFILES = Main.o Game.o Board.o Block.o Player.o Textures.o
OBJS = $(patsubst %, $(ODIR)/%, $(OBJFILES))
EXE = ttt

.Phony: depend clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $^ $(SFML)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm $(ODIR)/*.o $(EXE)
