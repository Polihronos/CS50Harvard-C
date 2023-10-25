#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>



int convert(string input);
int number = 0;

int main(void)
{
    string input = get_string("Enter a positive integer: ");
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));

}

int convert(string input)
{
    int count = strlen(input);
    int tempInt = 0;

    if (count == 0)
    {
        return number;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        tempInt = input[i] - '0';
        input[i] = '\0';
        convert(input);

        number = number * 10 + tempInt;
        return number;
    }
    return number;
}
