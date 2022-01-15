#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt for user's name
    string name = get_string("What's your name? ");

    //print greeting to user
    printf("hello, %s\n", name);
}
