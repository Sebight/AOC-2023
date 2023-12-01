#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[5];
    int value;
} digit;

digit digits[] = {
    {.word = "one",
     .value = 1},
    {.word = "two",
     .value = 2},
    {.word = "three",
     .value = 3},
    {.word = "four",
     .value = 4},
    {.word = "five",
     .value = 5},
    {.word = "six",
     .value = 6},
    {.word = "seven",
     .value = 7},
    {.word = "eight",
     .value = 8},
    {.word = "nine",
     .value = 9}};

void preprocess(char *out_line)
{
}

int main()
{
    FILE *pFile;
    pFile = fopen("input.txt", "r");

    int total = 0;

    char line_buffer[512];
    while (fgets(line_buffer, 512, pFile))
    {

        printf("a");

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