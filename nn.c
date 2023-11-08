#include "nn.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double hidden_calculations[numneurons] = {0};
double outputvec[numoutputs];

void Read_data(double weight_table[numlayers + 1][numneurons][numneurons], double input_table[numinputs], double bias_table[numlayers + 1], double outputvec[numoutputs])
{

    double inputs[numinputs];
    double weights[numlayers + 1][numneurons][numneurons];
    double bias[numlayers + 1];

Read_one:
    for (int i = 0; i < numlayers; i++)
    {

        if (i == 0)
        {
        Read_one_one:
            for (int j = 0; j < numinputs; j++)
            {
            Read_one_one_one:
                for (int k = 0; k < numneurons; k++)
                {
                    weights[i][j][k] = weight_table[i][j][k];
                }
            }
        }

        else
        {
        Read_one_two:
            for (int j = 0; j < numneurons; j++)
            {
            Read_one_two_one:
                for (int k = 0; k < numneurons; k++)
                {
                    weights[i][j][k] = weight_table[i][j][k];
                }
            }
        }
    }
Read_two:
    for (int i = 0; i < numoutputs; i++)
    {
    Read_two_one:
        for (int k = 0; k < numneurons; k++)
        {
            weights[numlayers][k][i] = weight_table[numlayers][i][k];
        }
    }

Read_three:
    for (int i = 0; i < numinputs; i++)
    {
        inputs[i] = input_table[i];
    }

Read_three_one:
    for (int i = 0; i <= numlayers; i++)
    {
        bias[i] = bias_table[i];
    }

    Forward_Propagation(weights, bias, inputs, outputvec);
}

double sigmoid(double x)
{ // The Activation Function
    return 1.0 / (1.0 + exp(-x));
}

void Forward_Propagation(double weights[numlayers + 1][numneurons][numneurons],
                         double bias[numlayers + 1], double inputs[numinputs], double outputvec[numoutputs])
{
    double calc = 0;

Forward_one:
    for (int i = 0; i < numlayers; i++)
    {
    Forward_one_one:
        for (int k = 0; k < numneurons; k++)
        {
            calc = 0; // Reset calc in each loop iteration
            if (i == 0)
            {
            Forward_one_one_one:
                for (int j = 0; j < numinputs; j++)
                {
                    calc += inputs[j] * weights[i][j][k]; // Update calc with the weighted sum
                }
            }
            else
            {
            Forward_one_one_two:
                for (int j = 0; j < numneurons; j++)
                {
                    calc += hidden_calculations[j] * weights[i][j][k]; // Update calc with the weighted sum
                }
            }
            calc += bias[i];                        // Add bias to the weighted sum
            hidden_calculations[k] = sigmoid(calc); // Apply the activation function
        }
    }

Forward_two:
    for (int i = 0; i < numoutputs; i++)
    {
        calc = 0; // Reset calc for new output neuron
    Forward_two_one:
        for (int j = 0; j < numneurons; j++)
        {
            calc += hidden_calculations[j] * weights[numlayers][j][i]; // Update calc with the weighted sum
        }
        calc += bias[numlayers];      // Add bias to the weighted sum
        outputvec[i] = sigmoid(calc); // Apply the activation function for the output neuron
    }
}