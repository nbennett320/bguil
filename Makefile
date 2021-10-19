CXX = g++
LIBS = -lstdc++fs -lSDL2 -lSDL2_ttf
CXXFLAGS = -g -std=c++2a -I $(INCLUDE) -I $(BACKUPDIR)
BIN = bin
SOURCE = src
INCLUDE = include
BACKUPDIR = $(INCLUDE)/backup
OBJ = \
	bguil.o \

LIST = $(addprefix $(BIN)/, $(OBJ))
VPATH = $(SOURCE) $(SOURCE)/backup

ifdef opt
CXXFLAGS += -Ofast
endif

all: bguil
bguil: $(LIST) main.cpp
	$(CXX) $(CXXFLAGS) -o bguil $(SOURCE)/main.cpp $(LIST) $(LIBS)

$(BIN)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f bguil *.o bin/*
