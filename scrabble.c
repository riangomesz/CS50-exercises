/* 
In the Scrabble game, players create words to score points, and the number of points is the sum of the point values of each letter in the word. 
A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z
1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10
Example: Player One types the word "code" making 7 points
         Player Two types the word "science" making 1 + 3 + 1 + 1 + 1 + 3 + 1 = 11 points 
                                                    s   c   i   e   n   c   e   
Resulting in Player Two winning because he scored more points
*/

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

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score = score + POINTS[word[i] - 65];
        }

        if (islower(word[i]))
        {
            score = score + POINTS[word[i] - 97];
        }
    }
    return score;
}


