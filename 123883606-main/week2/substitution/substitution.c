#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string rotate(string text, string key);

int main(int argc, string argv[])
{
    //make the terminal argument to take 26 keys
    if (argc < 2)
    {
        printf("key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("key\n");
        return 1;
    }
    int lenght_argv = strlen(argv[1]);
    if (lenght_argv != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    for (int i = 0; i < lenght_argv; i++)
    {
        if (isalpha(argv[1][i]))
        {

        }
        else
        {
            return 1;
        }
    }
    for (int i = 0; i < lenght_argv - 1; i++)
    {
        for (int j = i + 1; j < lenght_argv; j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] + 32 || argv[1][i] == argv[1][j] - 32)
            {
                return 1;
            }
        }
    }
    //get plaintext
    string text = get_string("plaintext: ");

    //function to cypher the text lower and uppercase sensitive
    string key = argv[1];
    string cypher = rotate(text , key);

    //print ciphertext
    printf("ciphertext: %s\n", cypher);

    return 0;
}

string rotate(string text, string key)
{
    int lenght = strlen(text);
    int intword[lenght];
    int ikey[strlen(key)];

    for (int i = 0; i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                intword[i] = text[i] - 'A';
            }
            if (islower(text[i]))
            {
                intword[i] = text[i] - 'a';
            }
        }
    }
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]))
        {
            if (isupper(key[i]))
            {
                ikey[i] = key[i] - 'A';
            }
            if (islower(key[i]))
            {
                ikey[i] = key[i] - 'a';
            }
        }
    }

    for (int i = 0; i < lenght; i++)
    {
        if (intword[i] < 27 && intword[i] > -1)
        intword[i] = (ikey[intword[i]]) % 26;
    }

    for (int i = 0; i < lenght; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                text[i] = intword[i] + 'a';
            }
            if (isupper(text[i]))
            {
                text[i] = intword[i] + 'A';
            }
        }
    }

    return text;
}