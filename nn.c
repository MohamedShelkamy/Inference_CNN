#include "nn.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double inputs[numinputs];
double weights[numlayers + 1][numneurons][numneurons];
double bias[numlayers + 1];
double hidden_calculations[numneurons] = {0};

void Read_data(double weight_table[numlayers + 1][numneurons][numneurons],double input_table[numinputs],double bias_table[numlayers + 1])
{

    for (int i = 0; i < numlayers; i++)
    {

        if (i == 0)
        {
            for (int j = 0; j < numinputs; j++)
            {
                for (int k = 0; k < numneurons; k++)
                {
                    weights[i][j][k] = weight_table[i][j][k];
                    printf("%d %d %d \n", i, j, k);
                    printf("%f \n", weights[i][j][k]);
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
                    printf("%d %d %d \n", i, j, k);
                    printf("%f \n", weights[i][j][k]);
                }
            }
        }
    }
    for (int i = 0; i < numoutputs; i++)
    {
        for (int k = 0; k < numneurons; k++)
        {
            weights[numlayers][k][i] = weight_table[numlayers][i][k];
            printf("%d %d %d \n", numlayers, k, i);
            printf("%f \n", weights[numlayers][k][i]);
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

    Forward_Propagation();
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
    FILE *file= fopen("output.txt","w");
    if(file == NULL){
        printf("error file is not accessible \n");
    }

    for (int i = 0; i < numoutputs; i++)
    {
        for (int j = 0; j < numneurons; j++)
        {
            calc += hidden_calculations[j] * weights[numlayers][j][i] + bias[numlayers];
        }
        fprintf(file, "%f \n", calc);


    }
    fclose(file);
}

/*int main()
{
    double weight_table[numlayers + 1][numneurons][numneurons] = {
        #include "weights.txt"
    };
    double input_table[numinputs] = {   
    #include "input.txt"
    };

    double bias_table[numlayers + 1] ={
    #include "bias.txt"
    };
    Read_data(weight_table,input_table,bias_table);
    return 0;
}*/