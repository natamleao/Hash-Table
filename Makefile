APPS = ./app
BIN = ./bin
INCLUDE = ./include
LIBDIR = ./lib
BUILD = ./build
SRC = ./src
FLAGS = -Wall -Werror  
FLAGGLUT = -lGL -lGLU -lglut

LIB = $(LIBDIR)/libebhash.a

all: \
    libeb \
	myapps

libeb: \
    $(BUILD)/hash.o \
	$(BUILD)/node.o \
	$(BUILD)/keyarray.o

myapps: \
	cleanapp \
	$(BIN)/app

$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@ 

$(LIB): $(BUILD)/hash.o $(BUILD)/node.o $(BUILD)/keyarray.o
	ar rcs $@ $^

$(BIN)/%: $(APPS)/%.c $(LIB)
	gcc $(FLAGS) $< -L$(LIBDIR) -lebhash -I $(INCLUDE) -o $@ $(FLAGGLUT)

run:
	$(BIN)/app

clean:
	rm -rf $(BIN)/* $(BUILD)/* $(LIBDIR)/*

cleanapp:
	rm -rf $(BIN)/*