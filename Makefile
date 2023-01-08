CC      = clang
CFLAGS  = -g -Wall -Wno-unused-parameter -pedantic -std=c17 -I.
TARGET  = main
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
DEPS    = main.c string_searching.c
OBJ    := $(DEPS:%.c=$(OBJ_DIR)/%.o)
space  :=
space  +=
sources = $(subst $(space),:,$(filter-out src/main.c, $(wildcard src/*)))

vpath %.c $(SRC_DIR):$(sources)

$(TARGET): $(OBJ)
	@$(CC) -o $(BIN_DIR)/$(TARGET) $(CFLAGS) $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONY: path clean
path:
	@mkdir {$(BIN_DIR),$(OBJ_DIR),$(SRC_DIR)}
clean:
	@rm $(OBJ_DIR)/* $(BIN_DIR)/*
run:
	@./bin/main
