// #include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(char *);
char rotate(char, int);

int main(int argc, char *argv[]) 
{
    // Checking number of command line input
    if (argc != 3)
    {
        printf("Usage: ./caesar key \"your message\"\n");
        return 1;
    }

    if (only_digits(argv[1]))
    {
        printf("Usage: ./caesar key \"your message\"\n");
        return 1;
    }

    // Converting input string to an integer
    int k = atoi(argv[1]);

    // Ask user for the text which needs to be encrypted
    char *text = argv[2];

    // Traversing the text msg and print its ciphertext
    printf("ciphertext: ");
    int i = 0;
    while (text[i] != '\0')
    {
        printf("%c", rotate(text[i], k));
        i++;
    }
    printf("\n");
}


// Checking if user input only positive integer
int only_digits(char *num)
{
    int i = 0;
    while (num[i] != '\0')
    {
        if (num[i] < 48 || num[i] > 57)
        {
            return 1;
        }
        i++;
    }
    return 0;
}


// Rotating a letter
char rotate(char ch, int key)
{
    if (!(isalpha(ch)))
    {
        return ch;
    }

    //int offset = (ch + key) % 26;
    key %= 26;

    // When adding offset with letter will return charachter which will not be a english alphabet, to prevent that situation we first check for that situation and if that occurs then first we subsract the letter from Z and then we substract the previous substaction result from offset, then we add present substraction result with 'A', doing this function will always return english letter.
    if (isupper(ch))
    {
        if (ch + key > 'Z')
        {
            // Below line we add with 'A', but we should count it also,so we substract 1
            return 'A' + (key - ('Z' - ch) - 1);
        }
    }
    else
    {
        if (ch + key > 'z')
        {
            return 'a' + (key - ('z' + 1 - ch));
        }
    }
    return ch + key;
}
