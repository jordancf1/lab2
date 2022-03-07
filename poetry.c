#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]){

    /*opening file for reading*/
    FILE *fPtr = NULL;
    fPtr = fopen(argv[1], "r");

    /*Tells program which line is currently being read, and is also used for output*/
    int currentLine;
    currentLine = 0;

    /*Used specifically for output, just tells how many words have been scanned in total*/
    int totalNumOfWords;
    totalNumOfWords = 0;

    /*Stands for words on current line, at the end of scanning this is the variable put into the array*/
    int wordsOnCurrLine;
    
    /*Stores current line as a string, this is used to split it and find out how many words there are*/
    char *tempArray;
    tempArray = malloc(sizeof(char) * MAX_LINE_LENGTH);

    /*Dynamically allocated array used to store how many words are in each line.*/
    int *wordArray = (int*)malloc(sizeof(int));

    while(!feof(fPtr)){

        //Resetting the words on current line to 0, since each iteration is a new line
        wordsOnCurrLine = 0;

        //Scans line and stores it in temporary variable
        fgets(tempArray, MAX_LINE_LENGTH, fPtr);

        /*Splits string and iterates through all words,
        each iteration adds 1 to both the variables representing the words on each line, and the total words*/
        char * token = strtok(tempArray, " ");
        while( token != NULL ) {
            token = strtok(NULL, " ");
            wordsOnCurrLine++;
            totalNumOfWords++;
        }

        if(currentLine == 0){
            /*if statement to find out if this is the first iteration,
            if so, the first spot of the wordArray is filled since at this time, the array is of size 1 from the malloc statement*/
            wordArray[0] = wordsOnCurrLine;
        }

        else{
            /*if this is not the first iteration,
            the array is expanded by using realloc and the size is expanded to the number of lines that have passed*/
            wordArray = (int*)realloc(wordArray, currentLine * (sizeof(int)));
            wordArray[currentLine] = wordsOnCurrLine;
        }
        //At the end of the while loop, the currentLines is increased by one
        currentLine++;
    }

    //Printing out expected output
    printf("%d words on %d lines\n", totalNumOfWords, currentLine);
    for(int i = 0; i < currentLine; i++){
        printf("%d ", wordArray[i]);
    }

    //New line for nicer formatting
    printf("\n");

    //Freeing all previously allocated memory
    free(wordArray);
    free(tempArray);
}