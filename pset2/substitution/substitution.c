#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//global for alphabet chars
string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

//declare prototypes
char switchletter(string key, char letter);

//main function
int main(int argc, string argv[])
{
    //retrun error if # of arguments is not 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //get key and ley legnth
    string key = argv[1];
    int keylength = strlen(key);

    //return error if key is not 26 chars
    if (keylength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //create count
    int count = 0;

    //create copy of alphabet
    char alphacopy[26] = "abcdefghijklmnopqrstuvwxyz";

    //loop through key
    for (int i = 0; i < 26; i++)
    {
        //return error if char in key is not alphabetic
        if (!isalpha(key[i]))
        {
            printf("Key must contain only contain alphabetic characters.\n");
            return 1;
        }

        //loop through alphabet
        for (int j = 0; j < 26; j++)
        {
            //check if char in key matches a char in alphabet
            if (tolower(key[i]) == alphacopy[j])
            {
                //remove matched char from alphabet and up the count
                alphacopy[j] = '_';
                count++;
                break;
            }
        }
    }

    //return error if loop didn;t match each char in alphabet
    if (count != 26)
    {
        printf("Key must contain not contain duplicate characters.\n");
        return 1;
    }

    //prompt for plain text and get length
    string plaintext = get_string("plaintext: ");
    int plaintextlength = strlen(plaintext);

    //copy plaintext to ciphertext
    string ciphertext = plaintext;

    //loop through plaintext chars
    for (int i = 0; i < plaintextlength; i++)
    {
        //get letter char
        char letter = plaintext[i];

        //check char is alphabetic
        if (isalpha(letter))
        {
            //switch out letter with new one
            char newletter = switchletter(key, letter);
            //insert new letter into cipertext string
            ciphertext[i] = newletter;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}

//function to switch letters
char switchletter(string key, char letter)
{
    //declare newletter
    char newletter;

    //loop through alphabet
    for (int i = 0; i < 26; i++)
    {
        //match letter in alphabet
        if (tolower(letter) == ALPHABET[i])
        {
            //switch out for matching letter in key
            newletter = key[i];
        }
    }

    //make new letter match state of original
    if (isupper(letter))
    {
        newletter = toupper(newletter);
    }
    else
    {
        newletter = tolower(newletter);
    }

    return newletter;
}
