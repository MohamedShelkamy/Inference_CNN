#include "nn.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    double weight_table[numlayers + 1][numneurons][numneurons] = {
#include "weights.txt"
    };
    double input_table[numinputs] = {
#include "input.txt"
    };

    double bias_table[numlayers + 1] = {
#include "bias.txt"
    };
    double outputvec[numoutputs];
    Read_data(weight_table, input_table, bias_table, outputvec);
    const char *goldenFilename = "golden.txt";
    const char *outputFilename = "output.txt";

    FILE *file = fopen("output.txt", "w");
    if (file == NULL)
    {
        printf("error file is not accessible \n");
    }
    for (int i = 0; i < numoutputs; i++)
    {
        fprintf(file, "%f \n", outputvec[i]);
    }

    fclose(file);

    FILE *goldenFile = fopen(goldenFilename, "r");
    FILE *outputFile = fopen(outputFilename, "r");

    if (goldenFile == NULL || outputFile == NULL)
    {
        perror("Error opening files");
        return 1;
    }

    int equal = 1; // Assume the files are equal initially

    char goldenChar, outputChar;
    while (1)
    {
        goldenChar = fgetc(goldenFile);
        outputChar = fgetc(outputFile);

        if (goldenChar != outputChar)
        {
            equal = 0;
            break;
        }

        if (goldenChar == EOF || outputChar == EOF)
        {
            break; // End of one or both files
        }
    }

    fclose(goldenFile);
    fclose(outputFile);

    if (equal)
    {
        printf("The files are identical.\n");
    }
    else
    {
        printf("The files are different.\n");
    }

    return 0;
}