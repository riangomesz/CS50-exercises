#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        // take user input
        n = get_int("Height:");
    }

    while( n < 1 || n > 8);

    for(int i = 0; i < n; i++)
    {
        printf("#\n");
    }
}