/* 
 * File:   main.c
 * Author: Mykayla Fernandes
 *
 * Alphabetize user input in a linked list and print the final result.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


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
char sorted[52][4];

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
void push(struct Node** head_ref, void *new_data, size_t data_size)
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
 * fpitr is used to access the function to be used for printing current node data.
 */
void printList(struct Node *node, void(*fptr)(void *))
{
    while(node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}

//function to print an integer
void printInt(void  *n)
{
    printf(" %d", *(int *)n);
}

//function to print a char
void printChar(void *c)
{
    printf(" %c", *(char *)c);
}


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
    int k; //duplicates iterator
    
    printf("GET INPUT FUNCTION...\n");
    
    
    /**/
    char sortArr(charInput)
    {
        for (k = 0; k < sizeof(sorted[j]); k++)
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




/*
 * print final alphabetized result
 * 
 * add non-zero elements of the sorting array to a result array
 * print the result array
 */
void getOutput()
{
    int x = 0; //iterator
    int y = 0; //2d iterator
    int z = 0; //results counter
    
    
    /***/
    char resultArr(charLetter)
    {
        for (z; z<sizeof(result); z++)
        {
            if (result[z] == 0)
            {
                //add letter to result array
                result[z] = charLetter;
                printf("result array now has: %c \t at index: %d\n", result[z], z);
                //go back to x dimension loop
                break;
            }
        }
        return charLetter;
    }
    
    
    printf("GET OUTPUT FUNCTION...\n");
    
    //iterate over y dimension in the sort array
    for (x; x<52; x++)
    {
        if (sorted[x] != 0)
        {   
            //iterate over x dimension for duplicates to add
            for (y; y < sizeof(sorted[x]); y++)
            {
                if (sorted[x][y] != 0)
                {
                    //check accuracy
                    printf("from index: %d, %d \t adding letter: %c \n", x, y, sorted[x][y]);

                    //loop through result array for a place to add the letter
                    resultArr(sorted[x][y]);
                }
                else
                {
                    printf("nothing in sorted[x][y] %d,%d\n", x, y);
                    break;
                }
            }y = 0;
        }
        else
        {
            printf("nothing in sorted[x]: %d \n", x);
        }
    }
    //print final result
    printf("result: %c%c%c%c \n", result[0], result[1], result[2], result[3]);
    
    
    //linked list
    struct Node *start = NULL;
    unsigned char_size = sizeof(result);
    int xyz = 3;
    
    for (xyz; xyz>=0; xyz--)
    {
        push(&start, &result[xyz], char_size);
    }
    printf("alphabetized linked list: \n");
    printList(start, printChar);
}

/*
 * main method
 */
int main() {
    
    getInput();
    getOutput();
    
    return (EXIT_SUCCESS);
}

