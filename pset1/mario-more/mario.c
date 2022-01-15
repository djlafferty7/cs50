#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //get input from user
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    //loop through rows
    for (int i = 0; i < height; i++)
    {
        //loop through first half of columns
        for (int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        //add middle spaces
        printf("  ");
        //loop through second half of columns
        for (int j = 0; j < height; j++)
        {
            if (i >= j)
            {
                printf("#");
            }
        }
        //print new line
        printf("\n");
    }
}
