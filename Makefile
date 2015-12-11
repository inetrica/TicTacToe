CC = g++
CFLAGS = -Wall -Werror
INCLUDE = -I./head
SDIR = src
ODIR = obj
OBJFILES = Main.o Board.o Block.o MainMenu.o
OBJS = $(patsubst %, $(ODIR)/%, $(OBJFILES))
EXE = ttt

.Phony: depend clean

all: $(EXE) 

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $^

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm $(ODIR)/*.o $(EXE)
