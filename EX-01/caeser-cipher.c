#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char *string = malloc(255 * sizeof(char));
    scanf("%s", string);
    string[strlen(string)] = '\0';
    int length = strlen(string);

    int k;
    scanf("%d", &k);
    for (int i = 0; i < length; i++)
    {
        if (islower(string[i]))
        {
            int ascii = (int)string[i] - 97;
            if (ascii > (25 - k))
            {
                string[i] = (char)((ascii) % (26 - k) + 97);
            }
            else
            {
                string[i] = (char)((ascii + k) + 97);
            }
        }

        if (isupper(string[i]))
        {
            int ascii = (int)string[i] - 65;
            if (ascii > (25 - k))
            {
                string[i] = (char)((ascii) % (26 - k) + 65);
            }
            else
            {
                string[i] = (char)((ascii + k) + 65);
            }
        }
    }
    printf("%s", string);

    free(string);
}
