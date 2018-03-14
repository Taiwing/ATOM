#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <libconfig.h>
#include "libft/libft.h"
#include "neural_struct.h"

/*config_w*/
void create_conf(char *name, int num_layers, int *sizes, char *actf);
void save_net(neural_net *net);
void write_net_parameters(neural_net *net, config_t *conf);
void write_neuron_actf(neural_net *net, config_t *conf);
void write_net_biases(neural_net *net, config_t *conf);
void write_net_weights(neural_net *net, config_t *conf);

/*config_r*/
void load_conf_data(char *conf, neural_net *net);
void get_net_parameters(neural_net *net, config_t *config, config_setting_t *net_parameters);
void get_neuron_actf(neural_net *net, config_setting_t *neuron_actf);
void get_net_values(neural_net *net, config_setting_t *net_values);

/*config*/
double rand_double(double min, double max);
char *get_conf_name(char *name);
int does_config_exist(char *name);


/*TODO*/
/*
** remake the config system with new configurable parameters:
**  - each and every neuron must be given an activation function (which also
**  means modifying neural_struct.h to include *f pointers in each neuron)
**  - make the cost function paramater (also include a pointer to the cost
**  function in the neural_net structure, and create the derivatives)
**  - also maybe include parameters such as the learning algorithm, the l_rate,
**  and maybe even the values for the parameters of these algorithms
**  (mini_batch_size, epochs, etc...)
**  - create a parameter structure to give to the l_algorithm
**  - mabe make different paramater files, one for the entire program wich would
**  set the default values for each algorithms
*/

#endif
