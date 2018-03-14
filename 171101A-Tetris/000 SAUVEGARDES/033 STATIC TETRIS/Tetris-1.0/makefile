CC = gcc

IDIR = src/include
ODIR = src/obj
CDIR = src
LIBDIR = lib
LOADLIBES = -lpthread -lSM -lICE -lX11 -lXext -lXcursor -lXinerama -lXrandr -lGL -lGLU -lfreetype -lz -lpng -ljpeg -lpulse-simple -lpulse -lasound -lopenal -lFLAC -logg -ldumb -lvorbisfile -lvorbis -logg

_DEPS = main.h fmain.h elements.h images.h jeu.h marathon.h sprint.h ultra.h score.h time.h lines.h pause.h aide.h constantes.h fenetre.h son.h data_files.h data_list.h options.h configuration.h
_OBJ = main.o fmain.o elements.o images.o jeu.o marathon.o sprint.o ultra.o score.o time.o lines.o pause.o aide.o constantes.o fenetre.o son.o data_files.o data_list.o options.o configuration.o
_LIBS = liballegro-static.a liballegro_primitives-static.a liballegro_font-static.a liballegro_ttf-static.a liballegro_audio-static.a liballegro_acodec-static.a liballegro_image-static.a

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
LIBS =  $(patsubst %,$(LIBDIR)/%,$(_LIBS))

CLFAGS = -I$(IDIR)
STATIC = `pkg-config --static --cflags allegro-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_audio-5.0 allegro_acodec-5.0 allegro_image-5.0`
LIBFLAGS = -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec -lallegro_image -lm

$(ODIR)/%.o: $(CDIR)/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

tetris-1.0: $(OBJ)
	$(CC) -g $(LOADLIBES) -o $@ $^ $(CFLAGS) $(LIBS) -lm

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
