// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
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
bool valid(string password)
{
    bool uflag = false, lflag = false, dflag = flase, sflag = false;

    int i = 0;
    while (password[i] != '\0')
    {
        ch char = password[i];
        if (char >= 65 && char <= 90)
        {
            uflag = true;
        }
        else if (char >= 97 && char <= 122)
        {
            lflag = true;
        }
        else if (char >= 48 && char <= 57)
        {
            dflag = true;
        }
        else if (char >= 33 && char <= 47)
        {
            sflag = true;
        }
        i++;
    }
    return (uflag && lflag && dflag && sflag);
}
