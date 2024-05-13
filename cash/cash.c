// least amount of coins for change owed
// coins available - 25c, 10c, 5c, 1c.
// input - change owed
// output - number of coins

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents -= 1;
    }

    int coins;
    {
        coins = quarters + dimes + nickels + pennies;
        printf("%i\n", coins);
    }
}
