#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = 0;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end = 0;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int countYear = 0; // keep track of number of years
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        countYear++;
    }

    // TODO: Print number of years
    printf("Years: %i \n", countYear);
}
