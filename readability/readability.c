#include <cs50.h>
#include <math.h>
#include <stdio.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void) 
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    printf("%d letters\n", letters);

    int words = count_words(text);
    printf("%d words\n", words);

    int sentences = count_sentences(text);
    printf("%d sentences\n", sentences);

    // Calculating grade
    float avg_letters = letters / (float)words * 100;
    float avg_sentences = sentences / float(words) * 100;
    int index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

// Counting letters in text
int count_letters(string text)
{
    int i = 0, count = 0;

    while (text[i] != '\0')
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count++;
        }
        i++;
    }

    return count;
}

// Counting words in text
int count_words(string text)
{
    int i = 0, count = 1;

    while (text[i] != '\0')
    {
        if (text[i] == 32)
        {
            count++;
        }
        i++;
    }

    return count;
}

// Counting sentences in text
int count_sentences(string text)
{
    int i = 0, count = 0;

    while (text[i] != '\0')
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count++;
        }
        i++;
    }

    return count;
}
