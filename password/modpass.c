// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <stdio.h>

int valid(char *password);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("No input given!\n");
        return 1;
    }
    char *password = argv[1];
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
int valid(char *password)
{
    int uflag = 0, lflag = 0, dflag = 0, sflag = 0;

    int i = 0;
    while (password[i] != '\0')
    {
        char ch = password[i];
        if (ch >= 65 && ch <= 90)
        {
            uflag = 1;
        }
        else if (ch >= 97 && ch <= 122)
        {
            lflag = 1;
        }
        else if (ch >= 48 && ch <= 57)
        {
            dflag = 1;
        }
        else
        {
            sflag = 1;
        }
        i++;
    }
    return (uflag && lflag && dflag && sflag);
}
