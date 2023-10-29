//#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int* decimalTObinary(int);

int main(void)
{
    // TODO
    //string msg = get_string("Message: ");
    char *msg = "Hello World";

    // Traversing the string and printing the msg in bit emoji
    int i = 0;
    while (msg[i] != '\0')
    {
        int *showcase = decimalTObinary(msg[i]);
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(showcase[j]);
        }
        printf("\n");
        i++;
    }

}

// Converting decimal to binary
int* decimalTObinary(int dnum)
{
    int *arr = malloc(sizeof(int) * BITS_IN_BYTE);
    int i = 0;

    while (dnum != 0)
    {
        arr[BITS_IN_BYTE - i - 1] = dnum % 2;
        dnum /= 2;
        i++;
    }

    return arr;
}

// printing bulbs
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
