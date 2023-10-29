// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

///#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

char* replace(char*);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("This command takes only one argument, Try again with only one argument\n");
        return 1;
    }

    // replacing vowels with visually similar digit
    printf("%s \n", replace(*(argv + 1)));
}

char* replace(char* word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        switch(toupper(word[i]))
        {
            case 'A': 
                word[i] = '6';
                break;
            case 'E':
                word[i] = '3';
                break;
            case 'I':
                word[i] = '1';
                break;
            case 'O':
                word[i] = '0';
                break;
            default:
                break;
        }
        i++;
    }

    return word;
}
                

