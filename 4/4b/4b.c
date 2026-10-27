
#include <stdio.h>
#include <ctype.h>

int main()
{
    char var[100];
    int i = 0, valid = 1;

    printf("Enter a variable name: ");
    scanf("%99s", var);

    if (!isalpha((unsigned char)var[0]))
    {
        valid = 0;
    }
    else
    {
        while (var[i] != '\0')
        {
            if (!isalnum((unsigned char)var[i]))
            {
                valid = 0;
                break;
            }
            i++;
        }
    }

    if (valid)
        printf("Valid variable name\n");
    else
        printf("Invalid variable name\n");

    return 0;
}

