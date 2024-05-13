#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int line;
    int column;
    int space;
    // Prompt the user for the pyramid's height
    do
    {
        height = get_int("height: ");
    }
    while (height < 1);

    // Print a pyramid of that height
    for (line = 0; line < height; line++)
    {
        // Print spaces
        for (space = 0; space < (height - line - 1); space++)
        {
            printf(" ");
        }
        // Print bricks
        for (column = 0; column <= line; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
