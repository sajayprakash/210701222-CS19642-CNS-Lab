#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lcase(char str[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}

void rspace(char *str, int len)
{
    int ct = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
            str[ct++] = str[i];
    }
    str[ct] = '\0';
}

int mod(int a)
{
    return (a % 5);
}

int evenlen(char *str, int len)
{
    if (len % 2 != 0)
    {
        str[len++] = 'z';
        str[len] = '\0';
    }
    return len;
}

void generateKeyTable(char key[], char keyTable[5][5])
{
    int k = 0;
    int filled[26] = {0};

    // Fill the key
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] == 'j')
        {
            key[i] = 'i';
        }

        if (filled[key[i] - 'a'] == 0)
        {
            keyTable[k / 5][k % 5] = key[i];
            filled[key[i] - 'a'] = 1;
            k++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (i + 'a' != 'j' && filled[i] == 0)
        {
            keyTable[k / 5][k % 5] = i + 'a';
            k++;
        }
    }
}

void findPosition(char keyTable[5][5], char ch, int *row, int *col)
{
    if (ch == 'j')
    {
        ch = 'i';
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyTable[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPair(char keyTable[5][5], char a, char b, char *cipher)
{
    int rowA, colA, rowB, colB;

    findPosition(keyTable, a, &rowA, &colA);
    findPosition(keyTable, b, &rowB, &colB);

    if (rowA == rowB)
    {
        cipher[0] = keyTable[rowA][(colA + 1) % 5];
        cipher[1] = keyTable[rowB][(colB + 1) % 5];
    }
    else if (colA == colB)
    {
        cipher[0] = keyTable[(rowA + 1) % 5][colA];
        cipher[1] = keyTable[(rowB + 1) % 5][colB];
    }
    else
    {
        cipher[0] = keyTable[rowA][colB];
        cipher[1] = keyTable[rowB][colA];
    }
}

void playfairCipher(char *str, char keyTable[5][5])
{
    for (int i = 0; i < strlen(str); i += 2)
    {
        char pair[2] = {str[i], str[i + 1]};
        char cipher[2];

        encryptPair(keyTable, pair[0], pair[1], cipher);

        str[i] = cipher[0];
        str[i + 1] = cipher[1];
    }
}

void displayKeyTable(char keyTable[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", keyTable[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char *str = malloc(255 * sizeof(char));
    char *key = malloc(255 * sizeof(char));
    char keyTable[5][5];

    printf("Enter the plaintext: ");
    scanf("%[^\n]%*c", str);

    printf("Enter the key: ");
    scanf("%[^\n]%*c", key);

    lcase(str, strlen(str));
    rspace(str, strlen(str));

    int len = evenlen(str, strlen(str));
    generateKeyTable(key, keyTable);

    printf("Key Table:\n");

    displayKeyTable(keyTable);
    playfairCipher(str, keyTable);

    printf("Encrypted text: %s\n", str);

    return 0;
}
