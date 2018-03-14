CC = gcc

IDIR = src/include
ODIR = src/obj
CDIR = src

_DEPS = main.h fmain.h images.h jeu.h marathon.h sprint.h ultra.h score.h time.h lines.h pause.h aide.h constantes.h fenetre.h son.h data_files.h data_list.h options.h configuration.h
_OBJ = main.o fmain.o images.o jeu.o marathon.o sprint.o ultra.o score.o time.o lines.o pause.o aide.o constantes.o fenetre.o son.o data_files.o data_list.o options.o configuration.o

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CLFAGS = -I$(IDIR)
LIBFLAGS = `pkg-config --libs allegro-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_audio-5.0 allegro_acodec-5.0 allegro_image-5.0` -lm

$(ODIR)/%.o: $(CDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tetris-1.0: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
