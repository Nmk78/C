// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    FILE *output = fopen(argv[2], "w");
//check the file is exicted or not
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    // TODO: Read samples from input file and write updated data to output file
const int header_size = 44;

    uint8_t header[header_size];

    fread(header, header_size, 1, input);
    fwrite(header, header_size, 1, output);

    int16_t buffer;

    while(fread(&buffer, sizeof(int16_t), 1, input))
{
        //Adjust the Volume by multiply the buffer with factor that we put as Argument in the first
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
}
    // Close files
    fclose(input);
    fclose(output);
}
