#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int count_words(string text);

int count_sentances(string text);

float formula(int letters, int words, int sentances);

int main(void)
{
    //get text from user
    string text = get_string("Text: ");

    //count number of letters, words, sentences
    int letters = count_letters(text);

    int words = count_words(text);

    int sentances = count_sentances(text);

    //printf("\nletters: %i\nwords: %i\nsentances: %i\n", letters , words, sentances );

    //calculate grade using formula
    int grade = formula(letters, words, sentances);

    //print grade between 1 and 16
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int letters = 0;
    int lenght = strlen(text);
    for (int i = 0; i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 1;
    int lenght = strlen(text);
    for (int i = 0; i < lenght; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }

    return words;
}

int count_sentances(string text)
{
    int sentance = 0;
    int lenght = strlen(text);
    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentance++;
        }
    }

    return sentance;
}

float formula(int letters, int words, int sentances)
{
    float grade = 0;
    float average_letters = ((float)letters / (float)words) * 100;
    float average_sentances = ((float)sentances / (float)words) * 100;

    grade = 0.0588 * average_letters - 0.296 * average_sentances - 15.8;

    grade = round(grade);

    return grade;
}