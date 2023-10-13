#include "nn.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double inputs[numinputs];
double weights[numlayers + 1][numneurons];
double bias[numlayers + 1];
double hidden_calculations[numneurons] = {0};

void Read_data()
{
    double weight_table[numlayers + 1][numneurons] = {
#include "weights.txt"
    };
    double input_table[numinputs] = {
#include "input.txt"
    };

    double bias_table[numlayers + 1] = {
#include "bias.txt"
    };

    for (int i = 0; i <= numlayers; i++)
    {
        for (int j = 0; j < numneurons; j++)
        {
            weights[i][j] = weight_table[i][j];
            printf("%d %d \n", i, j);
            printf("%f \n", weights[i][j]);
        }
    }

    for (int i = 0; i < numinputs; i++)
    {
        inputs[i] = input_table[i];
        printf("%d\n", i);
        printf("%f \n", inputs[i]);
    }

    for (int i = 0; i <= numlayers; i++)
    {
        bias[i] = bias_table[i];
        printf("%d \n", i);
        printf("%f \n", bias[i]);
    }
}

double sigmoid(double x)
{ // The Activation Function
    return 1.0 / (1.0 + exp(-x));
}

void Forward_Propagation()
{ // Inference stage
    double calc = 0;

    for (int i = 0; i < numlayers; i++)
    {

        for (int k = 0; k < numneurons; k++)
        {
            if (numlayers == 0)
            {
                for (int j = 0; j < numinputs; j++)
                {
                    calc += inputs[j] * weights[i][j] + bias[i];
                }
            }
            else
            {
                for (int j = 0; j < numneurons; j++)
                {
                    calc += hidden_calculations[j] * weights[i][j] + bias[i];
                }
            }
            hidden_calculations[k] = sigmoid(calc);
        }
    }

    for (int i = 0; i < numoutputs; i++)
    {
        for (int j = 0; j < numneurons; j++)
        {
            calc += hidden_calculations[j] * weights[numlayers - 1][j] + bias[numlayers - 1];
        }
        printf("%f", calc);
    }
}

int main()
{
    Read_data();
    return 0;
}