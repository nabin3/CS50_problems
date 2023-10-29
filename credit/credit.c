//#include <cs50.h>
#include <stdio.h>


long get_cardNumber(void);
int verify(long);
void type(long);


int main(void)
{
    // Take card number from user
    long card_number = get_cardNumber();

    // Verify whether the card is valid or not-valid, if valid then determine the type of card
    if (verify(card_number))
    {
        type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}


long get_cardNumber(void)
{
    long num;
    do
    {
        printf("Number: ");
        scanf("%li", &num);
    }
    while (num < 1);
    return num;
}


// Verification for valid card number
int verify(long num)
{
    long x = num;
    int count = 0;
    while (x > 0)
    {
        x /= 10;
        count++;
    }

    // Return false if card number-length is correct
    if (count < 13 || count > 16)
    {
        return 0;
    }

    // chechksum check by luhn's algorithm
    x = num;
    int flag = 1;
    int sum1 = 0, sum2 = 0;
    int res = 0;
    while (x > 0)
    {
        if (flag)
        {
            sum1 += x % 10;
            x /= 10;
            flag = 0;
        }
        else
        {
            res = (x % 10) * 2;
            sum2 += (res / 10) + (res % 10);
            res = 0;
            x /= 10;
            flag = 1;
        }
    }

    return ((sum1 + sum2) % 10 == 0);
}


// Determine type of card
void type(long num)
{
    // Trancat number until there remain only two digit
    while (num > 100)
    {
        num /= 10;
    }

    // Get unit digit and second digit of above trancated number
    int u_dig = num % 10;
    int s_dig = num / 10;

    if (s_dig == 3 && (u_dig == 4 || u_dig == 7))
    {
        printf("AMEX\n");
    }
    else if (s_dig == 5 && (u_dig >= 1 && u_dig <= 5))
    {
        printf("MASTERCARD\n");
    }
    else if (s_dig == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
