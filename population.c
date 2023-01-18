#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int start;
    do
    {
        start = get_int("Starting Population: ");
    }
    while(start < 9);

    int end;
    do
    {
        end = get_int("Ending population: ");
    }
    while(start > end);

    int year = 0;
    do
    {
        start = start + (start/3) - (start/4);
        year++;
    }
    while(start < end);

    printf("Years: %i\n", year);
}