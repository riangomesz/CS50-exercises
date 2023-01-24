/*
Programa feito em linguagem C  
*/

#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;

int main(void)
{
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i ++)
    {
         scores[i] = get_int("Pontuação:");
    }
    // Imprimir média
    printf ("Média: %d\n", (scores[0] + scores[1] + scores[2]) / TOTAL);
}
