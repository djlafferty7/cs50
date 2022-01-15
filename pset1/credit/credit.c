
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declare variables
    long long cardnumber;
    long long digits;
    int count;
    int first;
    int second;
    int sum;
    int temp;
    int luhn;

    //get card number and duplicate to digits
    cardnumber = get_long("Number: ");
    digits = cardnumber;

    //initialise counter
    count = 0;

    //loop through digits variable counting number of digits
    while (digits != 0)
    {
        digits = digits / 10;
        count++;
    }

    //return invalid if not 13, 15 or 16 digits
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALD\n");
    }

    //create empty array
    int number[count];

    //loop through card number adding individual numbers to array
    for (int i = 0; i < count; i++)
    {
        number[i] = cardnumber % 10;
        cardnumber = cardnumber / 10;
    }

    //save first and second digits
    first = number[count - 1];
    second = number[count - 2];

    //loop through every other number in array
    for (int i = 1; i < count; i += 2)
    {
        //multiply number by 2 and update it in array
        number[i] = number[i] * 2;
    }

    //initialise sum
    sum = 0;

    //loop through updated array and add it all up
    for (int i = 0; i < count; i++)
    {
        temp = (number[i] % 10) + (number[i] / 10 % 10);
        sum = temp + sum;
    }

    //equate luhns algorithm
    luhn = sum % 10;

    if (luhn == 0)
    {
        //check if mastercard or visa
        if (count == 16)
        {
            if (first == 5 && (second >= 1 && second <= 5))
            {
                printf("MASTERCARD\n");
            }
            else if (first == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //check if amex
        else if (count == 15)
        {
            if (first == 3 && (second == 4 || second == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //check if visa
        else if (count == 13)
        {
            if (first == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
