/*
 * getOutput() implementation file
 * 
 * exposes getOutput as a public function so that main.c can call it
 * 
 * resultArr() is a private function within this file
 */

#ifndef GET_OUTPUT_H
#define GET_OUTPUT_H

/*get-output variable declarations*/
extern int x; //iterator
extern int y; //2d arr iterator
extern int z; //results counter

extern void getOutput(void);

#endif /* GET_OUTPUT_H */