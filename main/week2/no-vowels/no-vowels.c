// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

char replace(char i);

int main(int argc, string argv[])
{
    int lenght = strlen(argv[1]);
    for (int i = 0; i < lenght; i ++)
    {
        argv[1][i] = replace(argv[1][i]);
        printf("%c\n", argv[1][i]);
    }
    printf("%s\n", argv[1]);
}

char replace(char i)
{

    switch (i)
    {
        case 'a':
            i = '6';
            break;
        case 'e':
            i = '3';
            break;
        case 'i':
            i = '1';
            break;
        case 'o':
            i = '0';
            break;
        default:
            break;
    }
    return i;
}