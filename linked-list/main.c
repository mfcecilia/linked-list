/* 
 * File:   main.c
 * Author: Mykayla Fernandes
 *
 * Alphabetize user input in a linked list and print the final result.
 */


//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//obtain public functions
#include "get-output.h"
#include "get-input.h"


/*
 * print the alphabet and index
 * 
 * used for testing the accuracy of my alphabetizing code
 */
void printLetters()
{
    int a = 0;
    int b = sizeof(characters);
    
    printf("printing alphabet...\n");
    
    for (a; a<b; a++)
    {
        printf("index: %d \n alphabet: %c \n", a, characters[a]);
    }
    printf("total number of characters is %d \n", b);
}



/*
 * main method
 */
int main() {
    
    getInput();
    getOutput();
    
    return (EXIT_SUCCESS);
}

