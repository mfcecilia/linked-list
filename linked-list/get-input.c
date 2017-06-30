/*
 * getInput() implementation file
 * 
 * exposes getInput as a public function so that main.c can call it
 * 
 * sortArr() is a private function within this file
 */

#include "get-input.h" /*include the header (not strictly necessary here)*/

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/*get-input variable definitions*/

//look-up table for alphabetizing
char characters[52] = {
    'a', 'A',
    'b', 'B',
    'c', 'C',
    'd', 'D',
    'e', 'E',
    'f', 'F',
    'g', 'G',
    'h', 'H',
    'i', 'I',
    'j', 'J',
    'k', 'K',
    'l', 'L',
    'm', 'M',
    'n', 'N',
    'o', 'O',
    'p', 'P',
    'q', 'Q',
    'r', 'R',
    's', 'S',
    't', 'T',
    'u', 'U',
    'v', 'V',
    'w', 'W',
    'x', 'X',
    'y', 'Y',
    'z', 'Z'
};

//user input variable (limit = 4 characters)
char input[4];  

//array of sorted user input characters
char sorted[52][4];

int i; //user input iterator
int j; //alphabetizing iterator
int k; //duplicates iterator



/*function to avoid having too many nested for loops in getInput()*/
char sortArr(char charInput)
{
    for (k=0; k < sizeof(sorted[j]); k++)
    {
        if (sorted[j][k] == 0)
        {
            sorted[j][k] = charInput;
            printf("duplicate added to sorted[j][k]: %c at %d,%d\n", sorted[j][k], j,k);
            break;
        }
    }
    return charInput;
}


/*
 * get the user input
 * 
 * analyze each character the user inputs them
 * find the index of the matching letter in the alphabet lookup table
 * add them to a sorting array at the index found in the lookup table 
 */
char getInput()
{ 
    printf("GET INPUT FUNCTION...\n");
    
    //ask for user input and only take 4 characters
    printf("Enter a string of 4 characters: ");
    for (i=0; i<4; i++)
    {
        //store user input
        scanf("%c", &input[i]);
        //check accuracy
        printf("character %d: %c \n", i, input[i]);
        
        //iterate over alphabet lookup table
        for (j=0; characters; j++)
        {
            //get index of user input as it relates to the alphabet lookup table
            if (input[i] == characters[j])
            {
                //check accuracy
                printf("input %c matches character at %d \n", input[i], j);
                //put input in a sort array at their new index (from lookup table)
                if (sorted[j][0] != 0)
                {
                    printf("DUPLICATE FOUND: %c \n", sorted[j][0]);
                    //2d array to handle duplicates
                    sortArr(input[i]);
                    break;
                }
                else
                {
                    sorted[j][0] = input[i];
                    break;
                }         
            }
        }
    }
}