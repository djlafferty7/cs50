#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    //declare variables
    int score;
    int length;
    int ascii;
    int letter;

    //get word length
    length = strlen(word);

    //initialise score
    score = 0;

    //loop through chars in word
    for (int i = 0; i < length; i++)
    {
        // change word to lower case
        word[i] = tolower(word[i]);

        //get ASCII value for char and equate letter position (0-25)
        ascii = (int)word[i];
        letter = ascii - 97;

        //check char is between a and z
        if (isalpha(word[i]))
        {
            //add points to score
            score += POINTS[letter];
        }
    }

    //return score
    return score;
}
