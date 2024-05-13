#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int index(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // Compute the Coleman-Liau index
    // letters per 100 words
    float l = letters / (float) words * 100;
    // sentences per 100 words
    float s = sentences / (float) words * 100;
    // grade
    float points = ((0.0588 * l) - (0.296 * s) - 15.8);

    // Print the grade level
    if (points >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (points < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int round_points = round(points);
        printf("Grade %d\n", round_points);
    }
}
int count_letters(string text)
{
    // Return the number of letters
    int lenght = strlen(text);
    int letters = 0;

    for (int i = 0; i < lenght; i++)
        if (isalpha(text[i]))
            letters++;

    return letters;
}

int count_words(string text)
{
    // Return the number of words
    int lenght = strlen(text);
    int words = 1;

    for (int i = 0; i < lenght; i++)
    {
        if (isblank(text[i]))
            words++;
    }

    return words;
}

int count_sentences(string text)
{
    // return the number of sentences
    int lenght = strlen(text);
    int sentences = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }

    return sentences;
}
