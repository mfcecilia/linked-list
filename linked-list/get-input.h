/*
 * getInput() implementation file
 * 
 * exposes getInput as a public function so that main.c can call it
 * 
 * sortArr() is a private function within this file
 */


#ifndef GET_INPUT_H
#define GET_INPUT_H

/*get-input variable declarations*/

//look-up table for alphabetizing
extern char characters[52];

//user input variable (limit = 4 characters)
extern char input[4];  

//array of sorted user input characters
extern char sorted[52][4];

//result array to print
extern char result[4];

extern int i; //user input iterator
extern int j; //alphabetizing iterator
extern int k; //duplicates iterator

extern char getInput(void);

#endif /* GET_INPUT_H */

