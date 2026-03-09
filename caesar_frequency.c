#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000
#define LETTERS_COUNT 26

char caesar_decrypt_char(char symbol, int key)
{
    if (isupper(symbol))
    {
        return ((symbol - 'A' - key + 26) % 26) + 'A';
    }
    else if(islower(symbol))
    {
        return ((symbol - 'a' - key + 26) % 26) + 'a';
    }
    return symbol;
}

char* caesar_decrypt(char* cipher, int key)
{
    int length = strlen(cipher);
    char* plaintext = malloc(sizeof(char) * (length + 1));
    int index = 0;
    while (cipher[index] != '\0')
    {
        plaintext[index] = caesar_decrypt_char(cipher[index], key);
        index++;
    }
    plaintext[index] = '\0';
    return plaintext;
}

int* count_letters(char* cipher)
{
    int* counts = malloc(sizeof(int) * LETTERS_COUNT);
    memset(counts, 0, sizeof(int) * (LETTERS_COUNT));

    int length = strlen(cipher);
    for(int i = 0; i < length; i++)
    {
        if(isalpha(cipher[i]))
        {
            int letter_index = toupper(cipher[i]) - 'A';
            counts[letter_index]++;
        }
    }
    return counts;
}

char get_most_common_letter(char* cipher)
{
    int* counts = count_letters(cipher);
    int maxIndex = 0;
    for(int i = 0; i < LETTERS_COUNT; i++)
    {
        if(counts[i] > counts[maxIndex])
        {
            maxIndex = i;
        }
    }
    char letter = maxIndex + 'A';
    return letter;
}

int get_key(char common_letter, char referent_letter)
{
    //TODO: Fix this function! - currently it returns negative numbers sometimes
    return referent_letter - common_letter;
}

void caesar_decrypt_analyze(char* cipher)
{
    //E, T, A, O
    char common_letter = get_most_common_letter(cipher);
    
    int key1 = get_key(common_letter, 'E');
    char* plaintextE = caesar_decrypt(cipher, key1);
    printf("%s (key = %d)\n", plaintextE, key1);

    int key2 = get_key(common_letter, 'T');
    char* plaintextT = caesar_decrypt(cipher, key2);
    printf("%s (key = %d)\n", plaintextT, key2);

    int key3 = get_key(common_letter, 'A');
    char* plaintextA = caesar_decrypt(cipher, key3);
    printf("%s (key = %d)\n", plaintextA, key3);

    int key4 = get_key(common_letter, 'O');
    char* plaintextO = caesar_decrypt(cipher, key4);
    printf("%s (key = %d)\n", plaintextO, key4);
}

int main()
{
    char cipher[MAXN];
    //TODO: read cipher from file
    printf("Enter ciphered text:\n");
    scanf("%s", cipher);
    caesar_decrypt_analyze(cipher);

    return EXIT_SUCCESS;
}