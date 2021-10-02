#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("Enter the amount in dollar, albeit sans dollar sign \n");
    float a;
    //checking whethr the user has given a positive value
    do
    {
        a = get_float("Change owed: ");
    }
    while (a <= 0.00);
    
    //conversion into pennies to avoid floating point imprecision
    int b = round(a * 100);
    
    //checking for quarters
    int c = b / 25;
    int d = b % 25;
    
    //checking for dimes
    int e = d / 10;
    int f = d % 10;
    
    //checking for nickels
    int g = f / 5;
    int h = f % 5;
    
    //checking for pennies
    int i = h / 1;
    
    //adding and printing number of coins required
    int n = c + e + g + i;
    printf("%i\n", n);
}