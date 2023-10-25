#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //make the program rune with only one command-line argument
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int lenght = strlen(argv[1]);
    for (int i = 0; i < lenght; i++)
    {
        if (isdigit(argv[1][i]))
        {
        }
        else
        {
        printf("key\n");
        return 1;
        }

    }

    // Convert argv[1] from a `string` to an `int`

    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string word = get_string("plaintext: ");

    // For each character in the plaintext:
    int lenght_word = strlen(word);
    int intword[lenght_word];
    for (int i = 0; i < lenght_word; i++)
    if (isalpha(word[i]))
    {
        if (isupper(word[i]))
        {
            intword[i] = word[i] - 'A';
        }
        if (islower(word[i]))
        {
            intword[i] = word[i] - 'a';
        }

    }

    // Rotate the character if it's a letter
    for (int i = 0; i < lenght_word; i ++)
    {
       intword[i] = (intword[i] + key) % 26;
    }

    for (int i = 0; i < lenght_word; i++)
    {
        if (isalpha(word[i]))
        {
            if (isupper(word[i]))
            {
                word[i] = intword[i] + 'A';
            }
            if (islower(word[i]))
            {
                word[i] = intword[i] + 'a';
            }
        }
    }
    printf("ciphertext: %s\n", word);
}