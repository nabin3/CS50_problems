#include<cs50.h>
#include <stdio.h>

int main(void)
{
    // Take height from user
    int height;
    do
    {
        height = get_int("Enter height for your wall: ");
    }
    while (height < 1 || height > 8);

    // printing wall

    // Calculating columns for given height
    int col = 2 * height + 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j >= height - i - 1 && j <= height + i + 2)
            {
                if (j == height || j == height + 1)
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }
            else if (j < height - i - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
