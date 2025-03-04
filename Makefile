CC = gcc
CFLAGS = -I./include -Wall -Werror
ARFLAGS = rcs
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
LIBNAME = ramViewer-lib
INCLUDE_DIR = include
LIB_DIR = lib
BUILD_DIR = build

.PHONY: all clean lib install

all: lib

lib: $(LIB_DIR)/$(LIBNAME).a

$(LIB_DIR)/$(LIBNAME).a: $(OBJ)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

install: lib
	@mkdir -p /usr/local/lib
	@mkdir -p /usr/local/include/mibiblioteca
	cp $(LIB_DIR)/$(LIBNAME).a /usr/local/lib/
	cp $(INCLUDE_DIR)/*.h /usr/local/include/mibiblioteca/

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) src/*.o

