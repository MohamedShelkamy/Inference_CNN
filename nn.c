#include "nn.h"
#include <stdio.h>
#include <math.h>
#define numlayers 1
#define numneurons 3
#define numinputs 3
#define numoutputs 1

double inputs[numinputs] = {1, 2, 3};
double weights[numlayers + 1][numneurons] = {{0.5, 0.6, 0.45}, {0.5, 0.6, 0.45}};
double biase[numlayers + 1] = {0.2, 0.3};

double hidden_calculations[numneurons] = {0};

double sigmoid(double x)
{ // The Activation Function
    return 1.0 / (1.0 + exp(-x));
}

void Forward_Propagation() // Inference stage
{
    double calc = 0;

    for (int i = 0; i < numlayers; i++)
    {

        for (int k = 0; k < numneurons; k++)
        {
            if (numlayers == 0)
            {
                for (int j = 0; j < numinputs; j++)
                {
                    calc += inputs[j] * weights[i][j] + biase[i];
                }
            }
            else
            {
                for (int j = 0; j < numneurons; j++)
                {
                    calc += hidden_calculations[j] * weights[i][j] + biase[i];
                }
            }
            hidden_calculations[k] = sigmoid(calc);
        }
    }

    for (int i = 0; i < numoutputs; i++)
    {
        for (int j = 0; j < numneurons; j++)
        {
           calc += hidden_calculations[j] * weights[numlayers-1][j] + biase[numlayers-1];
        }
        printf("%f",calc);
    }
}

int main()
{
    return 0;
}