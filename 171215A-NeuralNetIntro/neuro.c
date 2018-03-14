#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "neuroF.h"

int main(int argc, char **argv)
{
  int booLoop = 0; /*will indicate if there is an -l argument or not*/
  int loop = 0; /*number of times that we are going to repeat the learning process*/

  if(!(argc == (1 + WIDTH) || argc == (3 + WIDTH))) /*there must be as much parameters as the width of the net, or 2 more*/
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }
  else if(argc == (3 + WIDTH)) /*if there is 4 arguments*/
  {
    booLoop = 1;
    loop = atoi(argv[2]); /*then the second argument becomes the loop value*/
  }
  else if(argc == (1 + WIDTH)) /*if there is 2 arguments*/
  {
    loop = 1;
  }

  double target[WIDTH]; /*values wanted in output of the net*/
  target[0] = 0.01;
  target[1] = 0.99;

  net *neuNet = initializeNet(argv, booLoop);

  /*MAIN LOOP*/
  for(int l = 0; l < loop; l++)
  {
    /*loop of neural calculations*/
    for(int i = 1; i < DEEPNESS + 1; i++)
    {
      for(int j = 0; j < WIDTH; j++)
      {
        neuralInput(neuNet->layer[i - 1], neuNet->weight[i - 1][j], neuNet->bias[i - 1], &neuNet->layer[i][j]->input);
        neuralOutput(neuNet->layer[i][j]);
      }
    }

    /*now we display the output of the net*/
    printf("Net Output:\n");
    printf("o1 = %f\n", neuNet->layer[DEEPNESS][0]->output);
    printf("o2 = %f\n", neuNet->layer[DEEPNESS][1]->output);

    /*we're going to compare the targets to the output*/
    double error[WIDTH + 1];
    errorCalculation(neuNet->layer[DEEPNESS], target, error);

    /*now we calculate the influence of each weight on the final errors*/
    double weightInfluence[DEEPNESS][WIDTH][WIDTH];
    weightInfCalc(weightInfluence, error, target, neuNet);

    /*then we correct the weight values in fuction of the errors*/
    weightCorrection(weightInfluence, neuNet->weight);
  }

  /*FUNCTION SAVEWEIGHTS AND ADD A LOOP (-l) PARAMETER IN THE PARAMETERS TO REPEAT THE LEARNING*/
  saveWeights(neuNet->weight);

  return EXIT_SUCCESS;
}
