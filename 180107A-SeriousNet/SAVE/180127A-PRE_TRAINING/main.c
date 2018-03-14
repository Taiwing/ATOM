#include "main.h"

int main(int argc, char *argv[])
{
  char *name = get_params(argc, argv);

  if(!name)
  {
    printf("Error: wrong arguments\n");
    exit(EXIT_FAILURE);
  }

  neural_net *net = construct_neural_net(name);
  print_network(net);
  //train_network(net);

  data_set *training_data;
  data_set *test_data;

  if(!ft_strcmp(net->name, "handy"))
  {
    get_MNIST_data_set(&training_data, &test_data);
    SGD(net, training_data, 30, 10, 3.0, test_data);
  }
  else if(!ft_strcmp(net->name, "test"))
  {
    get_TEST_data_set(&training_data, &test_data, 600, 100);
    SGD(net, training_data, 30, 10, 3.0, test_data);
  }
  else if(!ft_strcmp(net->name, "test2"))
  {
    get_TEST_data_set(&training_data, &test_data, 10000, 1000);
    for(int i = 0; i < training_data->set_size; i++)
    {
      reset_neural_values(net);
      load_input(net, training_data->data[i]);
      feed_forward_print(net, net->actf);
      back_propagation(net, training_data->expout[i], 3.0);
    }
    printf("\nresults: %d / %d\n", evaluate(net, test_data), test_data->set_size);
    save_weights(net);
  }
  else if(!ft_strcmp(net->name, "424"))
  {
    get_424_data_set(&training_data, &test_data, 10000, 1000);
    for(int i = 0; i < training_data->set_size; i++)
    {
      reset_neural_values(net);
      load_input(net, training_data->data[i]);
      feed_forward_print(net, net->actf);
      back_propagation(net, training_data->expout[i], 3.0);
    }
    printf("\nresults: %d / %d\n", evaluate(net, test_data), test_data->set_size);
    save_weights(net);
  }
  else if(!ft_strcmp(net->name, "16N3"))
  {
    get_16N3_data_set(&training_data, &test_data, 10000, 1000);
    for(int i = 0; i < training_data->set_size; i++)
    {
      reset_neural_values(net);
      load_input(net, training_data->data[i]);
      feed_forward(net, net->actf);

      /*printf("input:\n");
      for(int j = 0; j < 16; j+=4)
        printf("%d%d%d%d\n", (int)training_data->data[i][j], (int)training_data->data[i][j+1], (int)training_data->data[i][j+2], (int)training_data->data[i][j+3]);
      printf("expout: %lf %lf %lf\n\n", net->layers[3][0]->output, net->layers[3][1]->output, net->layers[3][1]->output);*/

      back_propagation(net, training_data->expout[i], 3.0);
    }
    printf("\nresults: %d / %d\n", evaluate(net, test_data), test_data->set_size);
    save_weights(net);
  }
  else if(!ft_strcmp(net->name, "16N3C"))
  {
    get_16N3C_data_set(&training_data, &test_data, 10000, 1000);
    for(int i = 0; i < training_data->set_size; i++)
    {
      reset_neural_values(net);
      load_input(net, training_data->data[i]);
      feed_forward(net, net->actf);
      back_propagation(net, training_data->expout[i], 3.0);
    }

    printf("\nresults: %d / %d\n", evaluate(net, test_data), test_data->set_size);
    save_weights(net);
  }
  else
  {
    srand(time(NULL));
    double val = rand_double(-4.5, 4.5);
    double *input = (double *)malloc(net->sizes[0] * sizeof(double));
    for(int i = 0; i < net->sizes[0]; i++)
      input[i] = val * i;
    for(int i = 0; i < net->sizes[0]; i++)
      printf("input[%d] = %lf\n", i, input[i]);
    printf("\n");
    reset_neural_values(net);
    load_input(net, input);
    feed_forward(net, net->actf);
    printf("\n");
    for(int i = 0; i < net->sizes[net->num_layers-1]; i++)
      printf("output[%d] = %lf\n", i, net->layers[net->num_layers-1][i]->output);
  }

  return 0;
}
