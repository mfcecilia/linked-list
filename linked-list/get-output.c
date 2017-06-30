/*
 * getOutput() implementation file
 * 
 * exposes getOutput as a public function so that main.c can call it
 * 
 * resultArr() is a private function within this file
 */

#include "get-output.h" //include the header (not strictly necessary here)
#include "get-input.h"

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/*get-output variable definitions*/
int x = 0; //iterator
int y = 0; //2d arr iterator
int z = 0; //results counter

//result array to print
char result[4];

//linked list node
typedef struct Node{
    void *data;
    struct Node* next;
};

/*
 * function to add a node at the beginning of the linked list
 * 
 * expects a pointer to the data to be added and the size of that data
 */
static void push(struct Node** head_ref, void *new_data, size_t data_size)
{
    //allocate memory for node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = malloc(data_size);
    new_node->next = (*head_ref);
    
    //copy contents of new_data to newly allocated memory.
    //assumption: char takes 1 byte.
    int i;
    for (i=0; i<data_size; i++)
    {
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }
    
    //change head pointer as new node is added at the beginning
    (*head_ref) = new_node;
}


/*
 * function to print nodes in a given linked list
 * 
 * fptr is used to access the function to be used for printing current node data.
 */
static void printList(struct Node *node, void(*fptr)(void *))
{
    while(node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}

//function to print an integer
static void printInt(void  *n)
{
    printf(" %d", *(int *)n);
}

//function to print a char
static void printChar(void *c)
{
    printf(" %c", *(char *)c);
}

/*function to avoid having too many nested for loops in getOutput()*/
char resultArr(char character)
{
    for (z; z<sizeof(result); z++)
    {
        if (result[z] == 0)
        {
            //add character to result array
            result[z] = character;
            printf("result array now has: %c \t at index: %d\n", result[z], z);
            //go back to x dimension loop
            break;
        }
    }
    return character;
}


/*
 * print final alphabetized result
 * 
 * add non-zero elements of the 2d sorting array to a result array
 * print the result array
 * push contents of the result array to linked list
 * print linked list
 */
void getOutput()
{
    
    printf("GET OUTPUT FUNCTION...\n");
    
    //iterate over y dimension in the sort array
    for (x; x < sizeof(characters); x++)
    {
        if (sorted[x] != 0)
        {   
            //iterate over x dimension for duplicates to add
            for (y; y < sizeof(sorted[x]); y++)
            {
                if (sorted[x][y] != 0)
                {
                    //check accuracy
                    printf("from index: %d, %d \t adding character: %c \n", x, y, sorted[x][y]);

                    //loop through result array for a place to add the letter
                    resultArr(sorted[x][y]);
                }
                else
                {
                    printf("nothing in sorted[x][y] %d,%d\n", x, y);
                    break;
                }
            }y = 0; //restart 2d iterator before going to the next row
        }
        else
        {
            printf("nothing in sorted[x]: %d \n", x);
        }
    }
    //print final result
    printf("result array: %c%c%c%c \n", result[0], result[1], result[2], result[3]);
    
    
    //linked list setup
    struct Node *start = NULL;
    unsigned char_size = sizeof(result);
    int xyz = 3;
    
    for (xyz; xyz>=0; xyz--)
    {
        push(&start, &result[xyz], char_size);
    }
    //print linked list
    printf("alphabetized linked list: \n");
    printList(start, printChar);
}