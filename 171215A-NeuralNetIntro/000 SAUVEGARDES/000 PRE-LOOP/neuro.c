#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "neuroF.h"

int main(int argc, char **argv)
{
  if(argc != (1 + WIDTH)) /*there must be as much parameters as the width of the net*/
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  double target[WIDTH]; /*values wanted in output of the net*/
  target[0] = 0.01;
  target[1] = 0.99;

  net *neuNet = initializeNet(argv);

  /*loop of neural calculations*/
  printf("\nNeuron Values:\n");
  for(int i = 1; i < DEEPNESS + 1; i++)
  {
    for(int j = 0; j < WIDTH; j++)
    {
      neuralInput(neuNet->layer[i - 1], neuNet->weight[i - 1][j], neuNet->bias[i - 1], &neuNet->layer[i][j]->input);
      neuralOutput(neuNet->layer[i][j]);

      /*test*/
      printf("nI[%d][%d] = %f\nnO[%d][%d] = %f\n", i, j, neuNet->layer[i][j]->input, i, j, neuNet->layer[i][j]->output);
    }
  }

  printf("\nOutput:\no1 = %f\no2 = %f\n", neuNet->layer[2][0]->output, neuNet->layer[2][1]->output);

  /*we're going to compare the targets to the output*/
  double error[WIDTH + 1];
  errorCalculation(neuNet->layer[DEEPNESS], target, error);

  /*test*/
  printf("\nError:\n");
  for(int i = 0; i < WIDTH; i++)
  {
    printf("eO%d = %f\n", i+1, error[i]);
  }
  printf("eT = %f\n", error[WIDTH]);

  /*now we calculate the influence of each weight on the final errors*/
  double weightInfluence[DEEPNESS][WIDTH][WIDTH];
  weightInfCalc(weightInfluence, error, target, neuNet);

  /*then we correct the weight values in fuction of the errors*/
  weightCorrection(weightInfluence, neuNet->weight);

  /*FUNCTION SAVEWEIGHTS AND ADD A LOOP (-l) PARAMETER IN THE PARAMETERS TO REPEAT THE LEARNING*/

  return EXIT_SUCCESS;
}
