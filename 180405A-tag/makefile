CC = gcc
WARN = -Wall -Wextra -Wmissing-declarations -Wmissing-prototypes -Wredundant-decls -Wshadow -Wstrict-prototypes -Wformat=2 -Wpedantic

IDIR = src/include
ODIR = src/obj
CDIR = src

_DEPS = main.h\
optarg.h\
tag.h\
tag_query.h\
utils.h\
info.h\
xattr_max.h\

_OBJ = main.o\
match.o\
optarg.o\
tag_delete.o\
tag_get.o\
tag_list.o\
tag_query.o\
tag_set.o\
utils.o\


DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CLFAGS = -I$(IDIR)

$(ODIR)/%.o: $(CDIR)/%.c $(DEPS)
	$(CC) $(WARN) -g -c -o $@ $< $(CFLAGS)

tag: $(OBJ)
	$(CC) $(WARN) -g -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
