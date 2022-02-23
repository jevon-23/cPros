#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include "utils.h"

const int MAX_LINE_LEN = 2048; // If you have a line of code longer that 2048 chars in c you need to hit the enter button at least one time for me,

/*
If there is an error, we are going to output what went wrong and exit out. Will need to call my free func.
*/
void error(int code) {
  switch (code) {
    case 0: // Invalid .extension
      printf("Invalid file type. We want this to work for .py, .java, .c, and .golang sometime in the future, but a sof rn only .c files are available");
    default:
      printf("Something went wrong");
  }
  exit(-1);
}

/*
Checks to make sure that the file that is being checked is of the right .extension
*/
int checkFile(int argc, char **argv, char **fileName) {
  char pointer[100];  // a copy of the filename that we will traverse through
  strcpy(pointer, *fileName);
  char *point = pointer;

  // Shifting the pointer over to the .extension of the file
  point = strtok(point, ".");
  point = strtok(NULL, ".");

  char *types[] = {"py", "java", "c", "sh", "go"};

  for (int i = 0; i < 5; i++) {
    if (strcmp(point, types[i]) == 0) {
      if (i == 2) {
        return i; // Once all the others are implemented, we dont have to worry abuot this if condition anymore
      }
    }
  }
  error(0);
  return -1;
}

bool isFunc(char *theString) {

  // if, else, for, while, switch, struct, typedef
  if ((memcmp(theString, "if", 2) == 0) || (memcmp(theString, "else", 4) == 0))  {
    return false;
  }
  if ((memcmp(theString, "for", 3) == 0) || memcmp(theString, "while", 5) == 0) {
    return false;
  }
  if ((memcmp(theString, "switch", 5) == 0) || memcmp(theString, "struct", 5) == 0) {
    return false;
  }

  if ((memcmp(theString, "typedef", 7) == 0)) {
    return false;
  }

  return true;
}

/*
Inputs:
  theFile : a pointer to the .c file who's funcs we want to find

Outputs:
  List[aFunc] : a list of all of functions in this file

C does not support nested functions!!

What I am thinking is grab all of the lines that either end with '{' || '}'
-> if the first word in the string is "if", "for" or "while" or "typdef" or "struct"

This func is inconsistent for some reason. It crashes my program when it is supposed to go on to the next line
*/
aFunc* CfindFuncs(aFile *theFile) {

  aFunc *allFuncs = (aFunc *) malloc(sizeof(aFunc));  // Creating a list of all of the functions that we see
  allFuncs->numFuncs = 0;
  printf("set numFuncs, theFile->lineCount = %d\n", theFile->lineCount);
  int allFuncsLen = 0;
  int openVclose = 0; // How many open brackets vs. closed brackets we have.

  for (int i = 0; i < theFile->lineCount; i++) {
    for (int j = 0; j < strlen((*(theFile->contents + i))); j++) {
      // printf("i = %d, j = %d, val = %c\n", i, j, *(*(theFile->contents + i)+j));
      printf("strlen = %lu, i = %d, j = %d\n", strlen(*(theFile->contents + i)), i, j);
      // If we see an open bracket
      if (*(*(theFile->contents + i)+j) == '{') {
        bool func = isFunc(*(theFile->contents +i));

        if (func && openVclose == 0) {
          allFuncs = (aFunc *) realloc(allFuncs, allFuncsLen+1);
          (allFuncs + allFuncsLen)->start = j;

        }
        printf("found open bracket, set everything\n");
        openVclose++;
      }
       else if (*(*(theFile->contents + i)+j) == '}') {
        openVclose--;

        if (openVclose == 0) {
          (allFuncs + allFuncsLen)->numLines = i - (allFuncs + allFuncsLen)->start;
          allFuncs->numFuncs++;
          allFuncsLen++;

        }
        printf("found closed bracket, set everything\n");
      }
      // printf("reached bottom of for \n");
    }
  }

  printf("finished\n");
  // String regex for words->{||space{||tab{ -> }|| w+} || (w+\n)^}
  // Basically, if we see an open bracket w/ no space,
  return allFuncs;
}

/*
Removes the indentation of the contents by shifting all values as far left as possible
*/
void formatString(aFile *theFile, int lineInd, int startInd) {
  int end = 0; // Int repr length of string, used to remove excess chars after we push all vals far left

  // Shifting over
  for (int i = 0; *(*(theFile->contents + lineInd) + (startInd + i)) != '\0'; i++) {
    *(*(theFile->contents + lineInd) + i) = *(*(theFile->contents + lineInd) + startInd + i);

    if ((*(*(theFile->contents + lineInd) + (startInd + i + 1)) != '\0') || (*(*(theFile->contents + lineInd) + (startInd + i + 1)) != '\n')) {
      end  = startInd + i + 1;
    }
  }

  // Removing repeated values at the very end
  for (int i = end - startInd; i < end; i++) {
    *(*(theFile->contents + lineInd) + i) = '\0';
  }
}

/*
 Removes the indentations of theFiles' contents
*/
void formatFile(aFile *theFile) {

  for (int i = 0; i < theFile->lineCount; i++) {
    for (int j = 0; *(*(theFile->contents+i) + j) != '\0'; j++) {

      // Once we find our first non-whitespace value
      if (*(*(theFile->contents+i)+j) != ' ') {
        formatString(theFile, i, j);
        break;
      }
    }
  }
}
/*
Reads the file, stores the name and its contents inside a AFILE struct
*/
aFile readFile(char *fileName) {
  // Opening the file that we are reading
  FILE *currFile = fopen(fileName, "r");
  if (currFile == NULL) {
    error(1);
  }

  // Creating a new afile instance. Making room for the first line to be read from file
  aFile theFile;
  theFile.name = fileName;
  theFile.contents = (char **) malloc(sizeof(char *)); // The content that fileName holds
  *theFile.contents = (char *) malloc(sizeof(char) * MAX_LINE_LEN);
  theFile.lineCount = 0;

  // Read this line from the file, and storing it at a value inside of theContents
  for (int i = 0; fgets(*(theFile.contents + i), MAX_LINE_LEN, currFile); i++ ) {

    // Create space for the next line of code
    theFile.contents = (char **) realloc(theFile.contents, i+1);
    *(theFile.contents + i +1) = (char *) malloc(sizeof(char) * MAX_LINE_LEN);
    theFile.lineCount++;
  }
  fclose(currFile);
  formatFile(&theFile);
  printf("read %s\n", fileName);
  return theFile;

}
