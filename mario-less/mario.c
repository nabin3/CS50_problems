#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Taking height from user
    int height;
    do
    {
        height = get_int("Enter height: ");
    }
    while (height > 8 || height < 1);

    // Printing wall
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (j >= height -1 - i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
