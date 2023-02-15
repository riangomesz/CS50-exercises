/* Algorithm that traverses an Array in search of a requested number. 
If it finds it, it will tell the user "Found" otherwise "Not found" */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    for (int i = 0; i < 7; i++)
    {
         if (numbers[i] == 0)
         {
               printf("Found\n");
               return 0;
         }
    }
    printf("Not found\n");
    return 1;
}
