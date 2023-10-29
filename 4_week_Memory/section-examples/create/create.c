#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Checking for right amount of given argument
    if (argc != 2)
    {
        printf("Usage: ./create file_name\n");
        return 1;
    }

    // Alocating size for filename string dynamically
    char *filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));

    // Taking filename for command line argument
    sprintf(filename, "%s", argv[1]);

    // Opening file and check if the file specifile has successfully opened or not
    FILE *new_file = fopen(filename, "w");
    if (new_file == NULL)
    {
        printf("couldn't create file\n");
        return 2;
    }

    fclose(new_file);
    free(filename);
}



    
    
