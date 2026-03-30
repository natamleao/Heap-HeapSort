APPS = ./app
BIN = ./bin
INCLUDE = ./include
LIBDIR = ./lib
BUILD = ./build
SRC = ./src
FLAGS = -Wall -Werror  
FLAGGLUT = -lGL -lGLU -lglut

LIB = $(LIBDIR)/libebheap.a

all: \
    libeb \
	myapps

libeb: \
    $(BUILD)/heap.o \
	$(BUILD)/heapSort.o \
	$(BUILD)/calculateTime.o

myapps: \
	cleanapp \
	$(BIN)/app

$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@ 

$(LIB): $(BUILD)/heap.o $(BUILD)/heapSort.o $(BUILD)/calculateTime.o
	ar rcs $@ $^

$(BIN)/%: $(APPS)/%.c $(LIB)
	gcc $(FLAGS) $< -L$(LIBDIR) -lebheap -I $(INCLUDE) -o $@ $(FLAGGLUT)

run:
	$(BIN)/app

clean:
	rm -rf $(BIN)/* $(BUILD)/* $(LIBDIR)/*

cleanapp:
	rm -rf $(BIN)/*