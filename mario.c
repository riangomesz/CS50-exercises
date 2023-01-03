/* Mario (versão fácil) CS50 harvard.edu  */

#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        // take user input
        printf("Height: ");
        scanf("%d",&n);
    }

    while( n < 1 || n > 8);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
