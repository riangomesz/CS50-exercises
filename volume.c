// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//
const int HEADER_SIZE = 44;

int main (int argc, char*argv[])
{
    //
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor \n");
        return 1;
    }

    //
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file. \n");
        return 1;
    }
    //
    FILE *output = fopen(argv[2],"w");
    if (output == NULL)
    {
        printf("Could not open file. \n");
        return 1;
    }
        //
        float factor = atof(argv[3]);

        //
        uint8_t header[HEADER_SIZE];

        //
        fread(header, sizeof(uint8_t), HEADER_SIZE, input);

        //
        fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

        //
        int16_t sample;

            //
        while(fread(&sample, sizeof(int16_t), 1, input) == 1)
        {
            sample *= factor;
            fwrite(&sample, sizeof(int16_t), 1, output);
        }

    fclose(input);
    fclose(output);

}

