#include <stdio.h>
#include <math.h>
#include <cs50.h>

int summerize(long card);
bool is_valid(int sum);
string card_type(long card);

int main(void)
{
long card = 4003600000000014;

card = get_long("NUMBER: ");


int sum = 0;
sum = summerize(card);
//printf("sum: %i\n", sum);

bool valid;
valid = is_valid(sum);

//printf("%d\n", valid);

string type = "INVALID";
type = card_type(card);

//printf("%s\n", type);

if (valid == true)
{
    printf("%s\n", type);
}
else
printf("INVALID\n");

}

int summerize(long card)
{
    //counting how many symbols are in the card;
    int digits = 0;
    long card_clone = card;
    while (card_clone > 0)
    {
    digits++;
    card_clone = card_clone / 10;
    }

//making the long into smaller pieces and getting the sum by luhns algorithm
int n1 = 0;
int n2 = 0;
//n3 is for making n2 into a single digits
int n3 = 0;
int sum1 = 0;
int sum2 = 0;
int sum = 0;
for (int i = 0; i < digits; i ++)
{
    n1 = card % 10;
    card = card / 10;

    if (i % 2 != 0)
    {
        n2 = n1 * 2;
        n1 = 0;
    }
    sum1 = sum1 + n1;
    if (n2 >= 10)
    {
        n3 = n2 % 10;
        n2 = n2 / 10;
    }
    sum2 = sum2 + n2 + n3;
    n1 = 0;
    n2 = 0;
    n3 = 0;

    }
    sum = sum1 + sum2;

    return sum;
}

bool is_valid(int sum)
{
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

string card_type(long card)
{
    //counting how many symbols are in the card;
    int digits = 0;
    long card_clone = card;
    long card_clone2 = card;
    string type = "INVALID";
    while (card_clone > 0)
    {
        digits++;
        card_clone = card_clone / 10;
    }
    //the first number of the card
    int n1 = 0;
    //the first and second numbers (51,52, etc)
    int n2 = 0;
    //finding n1 and n2
    for (int i = 0; i < digits - 1; i++)
    {
        n1 = card_clone2 / 10;
        card_clone2 = card_clone2 / 10;
    }
    for (int j = 0; j < digits - 2; j++)
    {
        n2 = card / 10;
        card = card / 10;
    }

    if (digits == 16 && n2 >= 51 && n2 <= 55)
    {
        type = "MASTERCARD";
    }
    if (n1 == 4 && (digits == 13 || digits == 16))
    {
        type = "VISA";
    }
    else if (digits == 15 && (n2 == 34 || n2 == 37))
    {
        type = "AMEX";
    }

    return type;

}