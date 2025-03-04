CC = gcc
CFLAGS = -I./include -Wall -Werror
ARFLAGS = rcs
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
LIBNAME = ramViewer
LIB_DIR = lib
OBJS_DIR = objs

.PHONY: all clean lib install

all: lib

lib: $(LIB_DIR)/$(LIBNAME).a

$(LIB_DIR)/$(LIBNAME).a: $(OBJ)
	@mkdir -p $(LIB_DIR)
	ar $(ARFLAGS) $@ $^

%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

install: lib
	@mkdir -p /usr/local/lib
	@mkdir -p /usr/local/include/$(LIBNAME)
	cp $(LIB_DIR)/$(LIBNAME).a /usr/local/lib/
	cp include/*.h /usr/local/include/$(LIBNAME)/

clean:
	rm -rf $(OBJS_DIR) $(LIB_DIR) src/*.o

