#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    //declare variables
    string text;
    int letters;
    int words;
    int sentences;
    float averageL;
    float averageS;
    float grade;

    //get text input from user
    text = get_string("Text: ");

    //get # of letters
    letters = count_letters(text);

    //get # of words
    words = count_words(text);

    //get # of sentences
    sentences = count_sentences(text);

    //calculate average # letters per 100 words
    averageL = ((float)letters / words) * 100;

    //calculate average # sentences per 100 words
    averageS = ((float)sentences / words) * 100;

    //calculate grade level
    grade = (0.0588 * averageL) - (0.296 * averageS) - 15.8;

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(grade));
    }
}

//function to count letters in a string
int count_letters(string text)
{
    //decalre variables
    int length;
    int count;

    //get string length
    length = strlen(text);

    //initialise count
    count = 0;

    //loop through string
    for (int i = 0; i < length; i++)
    {
        //check if char is alphabetical
        if (isalpha(text[i]))
        {
            //increase counter by 1
            count++;
        }
    }
    //return count
    return count;
}

int count_words(string text)
{

    //decalre variables
    int length;
    int count;

    //get string length
    length = strlen(text);

    //initialise count
    count = 1;

    //loop through string
    for (int i = 0; i < length; i++)
    {
        //check if char is a space
        if (text[i] == ' ')
        {
            //increase counter by 1
            count++;
        }
    }
    //return count
    return count;
}

int count_sentences(string text)
{

    //decalre variables
    int length;
    int count;

    //get string length
    length = strlen(text);

    //initialise count
    count = 0;

    //loop through string
    for (int i = 0; i < length; i++)
    {
        //check if char is one of . ! ?
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            //increase counter by 1
            count++;
        }
    }
    //return count
    return count;
}
