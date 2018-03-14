CC = gcc
CCLFAGS = -I.
LIBFLAGS = `pkg-config --libs allegro-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_audio-5.0 allegro_acodec-5.0 allegro_image-5.0` -lm
DEPS = src/include/main.h src/include/fmain.h src/include/images.h src/include/jeu.h src/include/marathon.h src/include/sprint.h src/include/ultra.h src/include/score.h src/include/time.h src/include/lines.h src/include/pause.h src/include/aide.h src/include/constantes.h src/include/fenetre.h src/include/son.h src/include/data_files.h src/include/data_list.h src/include/options.h src/include/configuration.h
OBJ = src/main.o src/fmain.o src/images.o src/jeu.o src/marathon.o src/sprint.o src/ultra.o src/score.o src/time.o src/lines.o src/pause.o src/aide.o src/constantes.o src/fenetre.o src/son.o src/data_files.o src/data_list.o src/options.o src/configuration.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tetris-1.0: $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS) $(LIBFLAGS)
