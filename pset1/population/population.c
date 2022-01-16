#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declare variables
    int start;
    int end;
    int pop;
    int years;

    //Prompt for start size
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    //Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    //initialise pop and years
    pop = start;
    years = 0;

    //Calculate number of years until we reach threshold
    while (pop < end)
    {
        pop = pop + (pop / 3) - (pop / 4);
        years++;
    }

    //Print number of years
    printf("Years: %i\n", years);
}
