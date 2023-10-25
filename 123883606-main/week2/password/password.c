// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int lenght = strlen(password);
    int low = 0, up = 0, num = 0;
    int sym = 0;
    int checker = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (islower(password[i]))
        {
            low++;
        }
        if (isupper(password[i]))
        {
            up++;
        }
        if (isdigit(password[i]))
        {
            num++;
        }
        if (isdigit(password[i]) || isalpha(password[i]))
        {
            sym ++;
        }
    }
    //sym should be equal to lenght, if it is not then there is a symbol, checker should be the symbols
    if (sym < lenght)
    {
        checker ++;
    }
    if (low > 0 && up > 0 && num > 0 && checker > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
