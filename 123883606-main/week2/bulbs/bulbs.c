#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string word = get_string("Text goes here: ");
    int lenght = strlen(word);
    int num = 0;
    int arr[7];
    int bit = 0;
    for (int i = 0; i < lenght; i++)
    {
        //printf("\nword i = %i\n", word[i]);
        for (int k = 7; k > -1; k--)
        {
            num = word[i] % 2;
            word[i] = word[i] / 2;
            arr[k] = num;
            num = 0;

        }
        for (int j = 0; j < 8; j++)
        {
            bit = arr[j];
            print_bulb(bit);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
