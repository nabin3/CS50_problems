//#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

char subst(char, char *);
int right_key(char *);

int main(int argc, char *argv[]) 
{
    // Check if user give only one command-line argument or not
    if (argc != 2)
    {
        printf("usage: ./substitution key\n");
        return 1;
    }

    if (!right_key(argv[1]))
    {
        printf("Key must contain only 26 unique english letters\n");
        return 1;
    }

    char *msg = "Hello World!";

    // Printing ciphertext
    printf("ciphertext: ");
    int i = 0;
    while (msg[i] != '\0')
    {
        printf("%c", subst(msg[i], argv[1]));
        i++;
    }
    printf("\n");
}


// Checking if user input right type key
int right_key(char *key)
{
    int i = 0, alpha[26];

    // Intializing all element of alpha array with 0
    for (int j = 0; j < 26; j++)
    {
        alpha[j] = 0;
    }

    // Checking if given key contains any non alphabetic charachter
    while (key[i] != '\0')
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }

        // In the mean time also assigning frequency array alpha[] for checking uniqueness of every alphabet

        // If current alphabet is Uppercase then if bolck will be executed in case of lowercase alphabet else bolck will be executed
        if (isupper(key[i]))
        {
            alpha[key[i] - 'A']++;
        }
        else
        {
            alpha[key[i] - 'a']++;
        }

        i++;
    }

    // Here checking if given key conatins exactly 26 charachter or not 
    if (i != 26)
    {
        return 0;
    }

    for (int j = 0; j < 26; j++)
    {
        printf("%d ", alpha[j]);
    }
    


    // Here checking if every alphabet exist only once or not in given key with help of frequency array alpha
    for (int j = 0; j < 26; j++)
    {
        if (alpha[j] != 1)
        {
            return 0;
        }
    }

    return 1;
}


// Substituting alphabet charachters with respect to key
char subst(char ch, char *key)
{
    if (!isalpha(ch))
    {
        return ch;
    }

    // Following logic map charachter with key and return a corresponding charachter of key
    if (isupper(ch))
    {
        return toupper(key[ch - 'A']);
    }

    // Here used toupper() and tolower() for maintaing case of letter irrespective of key
    return tolower(key[ch - 'a']);
}
