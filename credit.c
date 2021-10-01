#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    //initializing or declaring variables
    long long card;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u = 0;
    int x;
    int y;
    int sum;
    int sum1 = 0;
    int sum2 = 0;
    
    //making sure the number is positive
    do
    {
        card = get_long_long("Number: ");
    }
    while (card < 1);
    
    long long card1 = card;
    long long card3 = card;
    long long card2 = card1 / 10;
    
    //multiplying every other digit by 2, starting from second last
    while (card2 > 0)
    {
        p = card2 % 10;
        p = p * 2;
        card2 = card2 / 100;
        if (p > 9)
        {
            q = p % 10;
            p = p / 10;
            r = p % 10;
            p = q + r;
        }
        sum1 = sum1 + p;
    }
    
    //adding every other digit starting from last
    while (card1 > 0)
    {
        s = card1 % 10;
        card1 = card1 / 100;
        sum2 = sum2 + s;
    }
    sum = sum1 + sum2;
    
    //to obtain the last digit
    t = sum % 10;
    
    //the number of digits
    while (card3 > 0)
    {
        card3 = card3 / 10;
        u++;
    }
    
    //obtaining the first and first two digits
    x = (int)(card / (long) pow(10, (u - 1)));
    y = (int)(card / (long) pow(10, (u - 2)));
    
    //checking whether the card number is valid or not
    if (t == 0)
    {
        if ((u == 15) && ((y == 34) || (y == 37)))
        {
            printf("AMEX\n");
        }
        else if ((u == 16) && ((y > 50) && (y < 56)))
        {
            printf("MASTERCARD\n");
        }
        else if (((u == 16) || (u == 13)) && (x == 4))
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