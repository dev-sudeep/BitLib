CC = gcc
AR = ar
CFLAGS = -fPIC -Wall -Wextra -I./include
LDFLAGS = -shared

SRC_DIR = srclib
OBJ_DIR = obj
LIB_DIR = lib

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

STATIC_LIB = $(LIB_DIR)/libbitlib.a
SHARED_LIB = $(LIB_DIR)/libbitlib.so

.PHONY: all clean directories

all: directories $(STATIC_LIB) $(SHARED_LIB)

directories:
	@mkdir -p $(SRC_DIR) $(OBJ_DIR) $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(OBJS)
	$(AR) rcs $@ $(OBJS)

$(SHARED_LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)
