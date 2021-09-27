#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("How much change is owed?\n");
    } 
    while (dollars < 0);
    printf("Change owed: %f\n", dollars);

    //convert the float into an integer 
    int cents = round(dollars * 100);
    int number_of_coins = 0;

    // if the biggest coin to use is 25
    if (cents % 25 >= 0)
    {
        //count the number of quarters needed
        number_of_coins = number_of_coins + (cents / 25);
        cents = cents % 25;
    }
    // if not, if the biggest coin to use is 10
    if (cents % 10 >= 0)
    {
        //count the number of dimes needed
        number_of_coins = number_of_coins + (cents / 10);
        cents = cents % 10;
    }

    if (cents % 5 >= 0)
    {
        //count the number of nickels needed
        number_of_coins = number_of_coins + (cents / 5);
        cents = cents % 5;
    }

    if (true)
    {
        //count the number of dimes needed
        number_of_coins = number_of_coins + cents;
    }
    
    printf("%i\n", number_of_coins);
}
