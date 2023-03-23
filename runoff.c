// Runoff activity from CS50 week 3

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name); // function to record a voter's preference
void tabulate(void); // function to count votes for all remaining candidates
bool print_winner(void); // function to determine if any candidate has won the election
int find_min(void); // function to find the minimun vote total for candidates not yet eliminated
bool is_tie(int min); //function to check if there is a tie among the remaining candidates
void eliminate(int min); // function to eliminate candidates who have the minimum number of votes

int main (int argc, string argv[])
{
    // Check for invalid usage
        // Check if number of command-line arguments passed to programis more than 2, (no candidate names provided). If this is the case the program prints error
    if (argc < 2)
    {
        printf("Usage: runoff [ candidate...] \n");
        return 1;
    }

    //Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximun number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
             // Set name and initial votes for each candidate
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
            // Get number of voters
    voter_count = get_int("Number of Voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
                // Record the vote for the current voter, current rank and candidate name
                // Return false if the vote is invalid, otherwise return true
            if (!vote(i,j,name))
            {
                printf("Invalid vote. \n");
                return 4;
            }
        }
                // Print a newline to separete the votes for each voters
        printf("\n");
    }

    //
    while (true)
    {
        //
        tabulate();

        //
        bool won = print_winner();
        if(won)
        {
            break;
        }

        //
        int min = find_min();
        bool tie = is_tie(min);

        //
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if(!candidates[i].eliminated)
                {
                    printf("%s\n",candidates[i].name);
                }
            }
            break;
        }

        //
        eliminate(min);

        //
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
        //
    return 0;
}

//
bool vote (int voter, int rank, string name)
{
     //
     for (int i = 0; i < candidate_count; i++)
     {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
     }
     return false;
}

//
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

//
bool print_winner(void)
{
    //
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n",candidates[i].name);
            return true;
        }
    }
    return false;
}

//
int find_min(void)
{
    //
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

//
bool is_tie(int min)
{
    //
    int eliminate = 0;
    int counter = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated)
        {
            eliminate++;
        }
        if (candidates[i].votes == min)
        {
            counter++;
        }
    }
    if (eliminate == counter)
    {
        return true;
    }
    return false;
}

//
void eliminate(int min)
{
    //
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}








