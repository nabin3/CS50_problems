#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // Checking for proper usage
    if (argc != 2)
    {
        printf("Proper Usage : ./pdf filename \n");
        return 1;
    }

    // Opening file
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    // Check if file exist
    if (file == NULL)
    {
        printf("File doesn't exist\n");
        return 2;
    }

    // To use this file type we should include stdint.h header file
    uint8_t buffer[4];
    fread(buffer, 1, 4, file);
    fclose(file);

    // Check if the given file is a pdf or not
    uint8_t comparator[] = {37, 80, 68, 70};
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != comparator[i])
        {
            printf("This file is not a pdf file\n");
            return 0;
        }
    }
    printf("This likely a pdf file\n");
    return 0;
}
