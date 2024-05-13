#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Error: Could not open memory card file\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];
    FILE *img = NULL;
    bool writing = false;
    int photo = 0;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous image file, if open
            if (img != NULL)
            {
                fclose(img);
                img = NULL;
            }

            // Generate filename for new image
            char filename[20];
            sprintf(filename, "%03d.jpg", photo++);

            // Open image file in append mode
            img = fopen(filename, "a");
            if (img == NULL)
            {
                printf("Error: Could not create image file\n");
                fclose(card);
                return 1;
            }
            writing = true;
        }

        // Write data to image file if writing is enabled
        if (writing && img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close remaining image file and memory card file
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
