#include "nn.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double hidden_calculations[numneurons] = {0};
double outputvec[numoutputs];

void Read_data(double weight_table[numlayers + 1][numneurons][numneurons],double input_table[numinputs],double bias_table[numlayers + 1],double outputvec[numoutputs])
{

    double inputs[numinputs];
    double weights[numlayers + 1][numneurons][numneurons];
    double bias[numlayers + 1];

    for (int i = 0; i < numlayers; i++)
    {

        if (i == 0)
        {
            for (int j = 0; j < numinputs; j++)
            {
                for (int k = 0; k < numneurons; k++)
                {
                    weights[i][j][k] = weight_table[i][j][k];
                }
            }  
        }

        else
        {
            for (int j = 0; j < numneurons; j++)
            {
                for (int k = 0; k < numneurons; k++)
                {
                    weights[i][j][k] = weight_table[i][j][k];
                }
            }
        }
    }
    for (int i = 0; i < numoutputs; i++)
    {
        for (int k = 0; k < numneurons; k++)
        {
            weights[numlayers][k][i] = weight_table[numlayers][i][k];
        }
    }

    for (int i = 0; i < numinputs; i++)
    {
        inputs[i] = input_table[i];
    }

    for (int i = 0; i <= numlayers; i++)
    {
        bias[i] = bias_table[i];
    }

    Forward_Propagation(weights,bias,inputs,outputvec);
}

double sigmoid(double x)
{ // The Activation Function
    return 1.0 / (1.0 + exp(-x));
}

void Forward_Propagation(double weights[numlayers + 1][numneurons][numneurons],
    double bias[numlayers + 1], double inputs[numinputs],double outputvec[numoutputs])
{ // Inference stage
    double calc = 0;

    for (int i = 0; i < numlayers; i++)
    {

        for (int k = 0; k < numneurons; k++)
        {
            if (i == 0)
            {
                for (int j = 0; j < numinputs; j++)
                {
                    calc += inputs[j] * weights[i][j][k] + bias[i];
                }
            }
            else
            {
                for (int j = 0; j < numneurons; j++)
                {
                    calc += hidden_calculations[j] * weights[i][j][k] + bias[i];
                }
            }
            hidden_calculations[k] = sigmoid(calc);
        }
    }

    for (int i = 0; i < numoutputs; i++)
    {
        for (int j = 0; j < numneurons; j++)
        {
            calc += hidden_calculations[j] * weights[numlayers][j][i] + bias[numlayers];
        }
        outputvec[i]=calc;

    }
}