#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO

    // Base case
    if (strlen(input) == 0)
    {
        return 0;
    }

    // Extracting last digit from input string and later putting '\0' in last digit's palce to trancate string by 1
    int last = strlen(input) - 1;
    int digit = input[last] - '0';
    input[last] = '\0';

    return digit + 10 * convert(input);
}
