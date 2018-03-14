#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libft/libft.h"

void create_conf(char *conf, int num_layers, int *sizes);
double rand_double(double min, double max);
char *get_conf_name(char *name);
int does_config_exist(char *name);

#endif
