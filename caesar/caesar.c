#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Use only 1 command line argument
    int n = 0, l;
    string pt = "";
    if (argc == 2)
    {
        while (argv[1][n] != '\0')
        {
            // Every character in arv[1] is a digit
            if (isdigit(argv[1][n]) == 0)
            {
                printf("key must only contain a positive integer.\n");
                return 1;
            }
            n++;
        }
        // Prompt a valid plaintext
        pt = get_string("plaintext:   ");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert a string to a int
    l = atoi(argv[1]) % 26;
    if (l >= 0)
    {
        printf("ciphertext:  ");
        int i = 0;
        while (pt[i] != '\0')
        {
            if (isupper(pt[i]))
            {
                printf("%c", ((pt[i] - 'A' + l) % 26) + 'A');
            }
            else if (islower(pt[i]))
            {
                printf("%c", ((pt[i] - 'a' + l) % 26) + 'a');
            }
            else
            {
                printf("%c", pt[i]);
            }
            i++;
        }
    }
    printf("\n");
    return 0;
}
