APPS = ./app
BIN = ./bin
INCLUDE = ./include
LIBDIR = ./lib
BUILD = ./build
SRC = ./src

FLAGS = -Wall -Werror
FLAGGLUT = -lGL -lGLU -lglut

LIB = $(LIBDIR)/libdsa.a

all: lib app

lib: \
    $(BUILD)/heap.o \
    $(BUILD)/heap_sort.o \
    $(BUILD)/execution_time.o

app: cleanapp $(BIN)/app

$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(LIB): \
    $(BUILD)/heap.o \
    $(BUILD)/heap_sort.o \
    $(BUILD)/execution_time.o
	ar rcs $@ $^

$(BIN)/app: $(APPS)/app.c $(LIB)
	gcc $(FLAGS) $< -L$(LIBDIR) -ldsa -I $(INCLUDE) -o $@ $(FLAGGLUT)

run:
	$(BIN)/app

clean:
	rm -rf $(BIN)/* $(BUILD)/* $(LIBDIR)/*

cleanapp:
	rm -rf $(BIN)/*