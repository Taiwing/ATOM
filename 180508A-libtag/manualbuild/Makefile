#compiler info
CC = gcc
CFLAGS = -g -Wall -Wextra -fPIC

#source directories
CDIR = src
HDIR = src/include
ODIR = obj

#source headers
_LDEPS = format.h\
info.h\
libtag.h\
optarg.h\
read_write.h\
tag.h\
tag_query.h\
utils.h\
xattr_max.h
_BDEPS = libtag.h

#C files
_LSRC = build_qtree.c\
format.c\
libtag.c\
match.c\
optarg.c\
query_checker.c\
read_write.c\
tag_delete.c\
tag_get.c\
tag_list.c\
tag_query.c\
tag_restore.c\
tag_save.c\
tag_set.c\
utils.c
_BSRC = main.c

#complete source paths
LDEPS = $(patsubst %,$(HDIR)/%,$(_LDEPS))
BDEPS = $(patsubst %,$(HDIR)/%,$(_BDEPS))
LSRC = $(patsubst %,$(CDIR)/%,$(_LSRC))
LOBJ = $(patsubst %,$(ODIR)/%,$(_LSRC:.c=.o))
BOBJ = $(patsubst %,$(ODIR)/%,$(_BSRC:.c=.o))

#program files
LIBNAME = libtag.so
BINNAME = tag
MAN = doc/tag.1

#install paths
LIB_DIR =	$(DESTDIR)/usr/lib
BIN_DIR = $(DESTDIR)/usr/bin
MAN_DIR = $(DESTDIR)/usr/share/man/man1

all: $(LIBNAME) $(BINNAME)

$(ODIR)/%.o: $(CDIR)/%.c $(LDEPS)
	$(CC) $(CFLAGS) -I$(HDIR) -c -o $@ $<

$(LIBNAME): $(LOBJ)
	$(CC) -shared -g -fPIC -Wl,-soname,$(LIBNAME) -o $(LIBNAME) -lc $(LOBJ)

$(BINNAME): $(LIBNAME)
	$(CC) $(CDIR)/$(_BSRC) -o $@  $< $(BDEPS)

install: $(LIBNAME) $(BINNAME)
	mkdir -p $(LIB_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(MAN_DIR)
	cp $(LIBNAME) $(LIB_DIR)
	cp $(BINNAME) $(BIN_DIR)
	gzip -fc doc/tag.1 > $(MAN_DIR)/tag.1.gz

uninstall:
	rm $(LIB_DIR)/$(LIBNAME)
	rm $(BIN_DIR)/$(BINNAME)
	rm $(MAN_DIR)/tag.1.gz

clean:
	rm -f $(ODIR)/*.o

.PHONY: all install uninstall clean
