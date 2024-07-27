#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt the user for some text

    string usertext = get_string("Text:\n");

    // count the number of letters, words and sentences in that text

    int l = count_letters(usertext);
    int w = count_words(usertext);
    int s = count_sentences(usertext);

    // compute the Coleman-Liau index

    float L = (float) l / w * 100;
    float S = (float) s / w * 100;
    float X = 0.0588 * L - 0.296 * S - 15.8;

    // rounding the output
    X = round(X);
    int X_rounded = (int) round(X);

    // print the grade level
    if (X < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (X >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", X_rounded);
    }
}

int count_letters(string text)
{
    // counter for letters
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else
        {
            continue;
        }
    }
    return letters;
}

int count_words(string text)
{
    // counter for words
    int words = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == ' ' && text[i - 1] == ' ')
        {
            continue;
        }
        else if (text[i] == ' ' && text[i + 1] == '\0')
        {
            continue;
        }
        else if (text[i] == ' ' && text[i] == text[0])
        {
            continue;
        }
    }
    return words;
}

int count_sentences(string text)
{
    // counter for sentences
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        else
        {
            continue;
        }
    }
    return sentences;
}
