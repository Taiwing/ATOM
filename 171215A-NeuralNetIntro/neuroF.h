#ifndef NEUROF_H
# define NEUROF_H
# define DEEPNESS 2
# define WIDTH 2

typedef struct neuron neuron;
struct neuron
{
  double  input;
  double  output;
};

typedef struct net net;
struct net
{
  double  weight[DEEPNESS][WIDTH][WIDTH];
  double  bias[DEEPNESS];
  neuron  *layer[DEEPNESS + 1][WIDTH]; /*replace it later by a neuron chained list*/
};

/*net loading*/
void loadWeights(double weight[DEEPNESS][WIDTH][WIDTH]); /*will load the weight values from a file*/
net *initializeNet(char **argv, int booLoop); /*will create and initialize the net values*/

/*I/O functions*/
void neuralInput(neuron *preLay[WIDTH], double weight[WIDTH], double bias, double *input); /*is gonna generate the input value*/
void neuralOutput(neuron *cell); /*is gonna generate the output value*/

/*learning*/
void errorCalculation(neuron *outLay[WIDTH], double target[WIDTH], double error[WIDTH + 1]); /*is gonna calculate the error values*/
/*calculates the influence of each the weights on the final errors*/
void weightInfCalc(double weightInfluence[DEEPNESS][WIDTH][WIDTH], double error[WIDTH + 1], double target[WIDTH], net *neuNet);
void weightCorrection(double weightInfluence[DEEPNESS][WIDTH][WIDTH], double weight[DEEPNESS][WIDTH][WIDTH]); /*will correct the weights*/
void saveWeights(double weight[DEEPNESS][WIDTH][WIDTH]); /*is gonna save the new weights in the synapses file*/

#endif
