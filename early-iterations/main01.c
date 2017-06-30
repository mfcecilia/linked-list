/* 
 * File:   main.c
 * Author: Mykayla Fernandes
 *
 * Alphabetize user input in a linked list and print the final result.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//look-up table for alphabetizing
char letters[52] = {
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
char sorted[52]; 

/*
 * print the alphabet and index
 * 
 * used for testing the accuracy of my alphabetizing code
 */
void printLetters()
{
    int a = 0;
    int b = sizeof(letters);
    
    printf("printing alphabet...\n");
    
    for (a; a<b; a++)
    {
        printf("index: %d \n letter: %c \n", a, letters[a]);
    }
    printf("total number of letters is %d \n", b);
}


/*
 * get the user input
 * 
 * analyze each character the user inputs
 * find the index of the matching letter in the alphabet lookup table
 * add them to a sorting array at the index found in the lookup table 
 */
char getInput()
{
    int i; //user input iterator
    int j; //alphabetizing iterator
    
    printf("getting input...\n");
    
    //ask for user input and only take 4 letters
    printf("Enter a string of 4 letters: ");
    for (i=0; i<4; i++)
    {
        //store user input
        scanf("%c", &input[i]);
        //check accuracy
        printf("character %d: %c \n", i, input[i]);
        
        //iterate over alphabet
        for (j=0; letters; j++)
        {
            //get index of user input as it relates to the alphabet lookup table
            if (input[i] == letters[j])
            {
                //check accuracy
                printf("input %c matches letter at %d \n", input[i], j);
                //put letters in a sort array at their new index
                sorted[j] = input[i];
                break;
            }
            else
            {
                j++;
            }
        }
    }
}

/*
 * print final alphabetized result
 * 
 * add non-zero elements of the sorting array to a result array
 * print the result array
 */
void getOutput()
{
    int x = 0; //iterator
    int y = sizeof(sorted);
    int z = 0; //results counter
    char result[4]; //result array to print
    
    printf("getting output...\n");
    
    //iterate over the sort array
    for (x; x<y; x++)
    {
        //only add to result array if the index contains a letter
        if (sorted[x] != 0)
        {
            //check accuracy
            printf("index: %d \n letter: %c \n", x, sorted[x]);
            //add letter to result array
            result[z] = sorted[x];
            //prep result array for next alphabetized letter
            z++;
        }
    }
    //print final result
    printf("result: %c%c%c%c", result[0], result[1], result[2], result[3]);
}

/*
 * main method
 */
int main() {

    getInput();
    getOutput();

    return (EXIT_SUCCESS);
}

