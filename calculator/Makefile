CC := gcc
DEBUG := 
CFLAGS := -c -fPIC
LIBFLAGS := -shared -o

BIN_DIR := bin
SRC_DIR := src
OBJ_DIR := build
HDR_DIR := headers

LIBS := libadd.so libsub.so libmul.so libdiv.so

BIN := calculator
OBJ := add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o 
SRC := add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c

LDFLAGS := -ldl

.PHONY: all debug create_dir clean

all: create_dir $(BIN_DIR)/$(BIN)

create_dir:
	mkdir $(BIN_DIR)
	mkdir $(OBJ_DIR)

debug: DEBUG += -g 
debug: all

$(BIN_DIR)/$(BIN): $(OBJ_DIR)/$(OBJ) $(LIBS) $(SRC_DIR)/$(BIN).c $(HDR_DIR)/functions.h
	$(CC) $(DEBUG) $(SRC_DIR)/$(BIN).c -o $(BIN_DIR)/$(BIN) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(DEBUG) $< -o $@

libadd.so:
	$(CC) $(LIBFLAGS) $(BIN_DIR)/libadd.so $(OBJ_DIR)/add.o

libsub.so:
	$(CC) $(LIBFLAGS) $(BIN_DIR)/libsub.so $(OBJ_DIR)/sub.o

libmul.so:
	$(CC) $(LIBFLAGS) $(BIN_DIR)/libmul.so $(OBJ_DIR)/mul.o

libdiv.so:
	$(CC) $(LIBFLAGS) $(BIN_DIR)/libdiv.so $(OBJ_DIR)/div.o

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
