// Program that encrypts messages using Caesar's cipher
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
bool check_valid_key(string s);

int main(int argc, string argv[])
{
    // Check if the user gave a valid key
    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // To convert the string to an integer
    int key = atoi(argv[1]); // "13" -> 13

    // User Input
    string plaintext = get_string("plaintext: ");

    // Output
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Find alphabets to convert
        char c = plaintext[i];
       if (isalpha(c))
        {
            // Characters for the algorithm
            char m = 'A';
            if (islower(c))
            {
                m = 'a';
            }
            // Caesar's Algorithm
            printf("%c", (c - m + key) % 26 + m);
        }
        // To leave special characters alone
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

// Function for checking if the user provided the correct key
bool check_valid_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        if (!isdigit(s[i]))
        {
            return false;
        }
    return true;
}