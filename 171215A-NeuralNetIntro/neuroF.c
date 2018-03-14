#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "neuroF.h"

void loadWeights(double weight[DEEPNESS][WIDTH][WIDTH])
{
  FILE *synapses = fopen("synapses.txt", "r");

  char buffer[256] = "";

  for(int i = 0; i < DEEPNESS; i++)
  {
    for(int j = 0; j < WIDTH; j++)
    {
      for(int k = 0; k < WIDTH; k++)
      {
        fgets(buffer, 256, synapses);
        weight[i][j][k] = atof(buffer);
      }
    }
  }

  fclose(synapses);
}

net *initializeNet(char **argv, int booLoop)
{
  net *neuralNet = malloc(sizeof(net)); /*creates the net structure*/

  loadWeights(neuralNet->weight); /*this part of the structure must be changed manually every time the WIDTH changes*/
  neuralNet->bias[0] = 0.35;
  neuralNet->bias[1] = 0.60;

  /*creates the neuronal layers of the net*/
  for(int i = 0; i < DEEPNESS + 1; i++)
  {
    for(int j = 0; j < WIDTH; j++)
    {
      neuralNet->layer[i][j] = malloc(sizeof(neuron));
    }
  }

  /*initialization of the input neurons*/
  for(int i = 0; i < WIDTH; i++)
  {
    neuralNet->layer[0][i]->input = 0; /*the first neural layer has no input, it IS the input of the net*/
    if(booLoop)
      neuralNet->layer[0][i]->output = atof(argv[i + 3]); /*value entered by user*/
    else
      neuralNet->layer[0][i]->output = atof(argv[i + 1]); /*value entered by user*/
  }

  return neuralNet;
}

void neuralInput(neuron *preLay[WIDTH], double weight[WIDTH], double bias, double *input)
{
  *input = (weight[0] * preLay[0]->output) + (weight[1] * preLay[1]->output) + (bias * 1);
}

void neuralOutput(neuron *cell)
{
  cell->output = 1 / (1 + exp(-cell->input));
}

void errorCalculation(neuron *outLay[WIDTH], double target[WIDTH], double error[WIDTH + 1])
{
  error[WIDTH] = 0; /*reinitialization of the error value for the ll*/
  for(int i = 0; i < WIDTH; i++)
  {
    error[i] = 0.5 * pow((target[i] - outLay[i]->output), 2);
    error[WIDTH] += error[i];
  }
}

void weightInfCalc(double weightInfluence[DEEPNESS][WIDTH][WIDTH], double error[WIDTH + 1], double target[WIDTH], net *neuNet)
{
  /*dError/output2*/
  double dEO20, dEO21;
  dEO20 = -(target[0] - neuNet->layer[2][0]->output);
  dEO21 = -(target[1] - neuNet->layer[2][1]->output);

  /*doutput2/input2*/
  double dO20I20, dO21I21;
  dO20I20 = neuNet->layer[2][0]->output * (1 - neuNet->layer[2][0]->output);
  dO21I21 = neuNet->layer[2][1]->output * (1 - neuNet->layer[2][1]->output);

  /*dinput2/weightX*/
  double dI20w5, dI20w6, dI21w7, dI21w8;
  dI20w5 = neuNet->layer[1][0]->output;
  dI20w6 = neuNet->layer[1][1]->output;
  dI21w7 = neuNet->layer[1][0]->output;
  dI21w8 = neuNet->layer[1][1]->output;

  /*dError/output1*/
  double dEO10, dEO11, dEO100, dEO101, dEO110, dEO111;
  dEO100 = dEO20 * dO20I20 * neuNet->weight[1][0][0];
  dEO101 = dEO21 * dO21I21 * neuNet->weight[1][1][0];
  dEO10 = dEO100 + dEO101;

  dEO110 = dEO20 * dO20I20 * neuNet->weight[1][0][1];
  dEO111 = dEO21 * dO21I21 * neuNet->weight[1][1][1];
  dEO11 = dEO110 + dEO111;

  /*doutput1/input1*/
  double dO10I10, dO11I11;
  dO10I10 = neuNet->layer[1][0]->output * (1 - neuNet->layer[1][0]->output);
  dO11I11 = neuNet->layer[1][1]->output * (1 - neuNet->layer[1][1]->output);

  /*weight influences of the first layer*/
  weightInfluence[0][0][0] = dEO10 * dO10I10 * neuNet->layer[0][0]->output;
  weightInfluence[0][0][1] = dEO10 * dO10I10 * neuNet->layer[0][1]->output;
  weightInfluence[0][1][0] = dEO11 * dO11I11 * neuNet->layer[0][0]->output;
  weightInfluence[0][1][1] = dEO11 * dO11I11 * neuNet->layer[0][1]->output;

  /*weight influences of the second layer*/
  weightInfluence[1][0][0] = dEO20 * dO20I20 * dI20w5;
  weightInfluence[1][0][1] = dEO20 * dO20I20 * dI20w6;
  weightInfluence[1][1][0] = dEO21 * dO21I21 * dI21w7;
  weightInfluence[1][1][1] = dEO21 * dO21I21 * dI21w8;
}

void weightCorrection(double weightInfluence[DEEPNESS][WIDTH][WIDTH], double weight[DEEPNESS][WIDTH][WIDTH])
{
  double lRate = 0.5; /*learning rate*/
  int c = 0;
  for(int i = 0; i < DEEPNESS; i++)
  {
    for(int j = 0; j < WIDTH; j++)
    {
      for(int k = 0; k < WIDTH; k++)
      {
        c++;
        weight[i][j][k] = weight[i][j][k] - (lRate * weightInfluence[i][j][k]);
      }
    }
  }
}

void saveWeights(double weight[DEEPNESS][WIDTH][WIDTH])
{
  FILE *synapses = fopen("synapses.txt", "w+");

  char buffer[256] = "";

  for(int i = 0; i < DEEPNESS; i++)
  {
    for(int j = 0; j < WIDTH; j++)
    {
      for(int k = 0; k < WIDTH; k++)
      {
        sprintf(buffer, "%f\n", weight[i][j][k]);
        fprintf(synapses, "%s", buffer);
      }
    }
  }

  fclose(synapses);
}
