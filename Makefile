CC = g++
CFLAGS = -Wall -Werror
SFML = -lsfml-graphics -lsfml-window -lsfml-system
INCLUDE = -I./head
SDIR = src
ODIR = obj
TDIR = testsrc
TSCRIPTDIR = testing
TESTFILES = tBlock.o tBoard.o tGame.o tPlayer.o tGameState.o
OBJFILES = Main.o Game.o Board.o Block.o Player.o Textures.o GameState.o StateEvaluator.o
OBJS = $(patsubst %, $(ODIR)/%, $(OBJFILES))
TESTOBJS = $(patsubst %, $(TDIR)/%, $(TESTFILES))
TESTS = $(patsubst %.o, $(TSCRIPTDIR)/%, $(TESTFILES))
EXE = ttt

.Phony: depend clean

all: $(EXE) $(TESTS)

$(TESTS): $(TESTOBJS)
	$(CC) $(CFLAGS) -o $@ $(@:$(TSCRIPTDIR)/%=$(TDIR)/%).o $(OBJS:$(ODIR)/Main.o=) $(SFML)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $^ $(SFML)

$(TDIR)/%.o: $(TDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -g

clean:
	rm $(ODIR)/*.o $(EXE)

cleanTests:
	rm $(TDIR)/*.o $(TESTS)
