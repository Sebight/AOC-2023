#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *pFile;
    pFile = fopen("input.txt", "r");

    int total = 0;

    char line_buffer[512];
    while (fgets(line_buffer, 512, pFile))
    {
        char *first_sight = NULL;
        char *last_sight = NULL;

        {
            for (size_t i = 0; i < strlen(line_buffer); i++)
            {
                if (isdigit(line_buffer[i]))
                {
                    if (first_sight == NULL)
                    {
                        first_sight = &line_buffer[i];
                        continue;
                    }
                    
                    last_sight = &line_buffer[i];
                }
            }

            int output = 0;
            output = output * 10 + (*first_sight - '0');
            output = output * 10 + (last_sight == NULL ? (*first_sight - '0') : (*last_sight - '0'));

            total = total + output;
        }
    }

    printf("%d", total);

    fclose(pFile);

    return 0;
}