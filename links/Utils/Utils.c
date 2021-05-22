#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#include<unistd.h>
#include <float.h>
#include "Utils.h"


const char *thePath = ".allClases";

void error(int type) {

  switch(type){
    case 1:
      printf("Could not read classes from .allClasses.\n");
      break;
    case 2:
      printf("could not write files to .allClasses.\n");
      break;
    case 3:
      printf("init failed.\n");
      break;
    case 4:
      printf("This class already exists.\n");
      break;
    case 5:
      printf("this link has been used for a previous class, which is the one that was printed above.\n");
    case 6:
      printf("this class does not exist\n");

    default:
      printf("something broke but I dont have an index for it yet.\n");
  }

  exit(-1);

}

// Creates the head node and intitates the file.
void init() {

  // Creating head
  class *theClass = (class *) malloc(sizeof(class));
  strcpy(theClass->theClass, "Head");
  strcpy(theClass->subClass, "Node");
  theClass->len = 1;

  // Making list of all nodes
  class **allClasses = (class **) malloc(sizeof(class **));
  allClasses[0] = theClass;


  writeFile(allClasses);  // Writing nodes to file
  freeClasses(allClasses);  // Freeing obj

}

// Opens a the website given from link
// Inputs: link -> the website that we will like to open
void getWebsite(char *link) {

  // If http or https does not begin our website link, system() will look for a file instead of a web page.
  char *http = "http://"; //
  char *https = "https://";

  char command[100];  // What we will be passing in to the system()
  strcpy(command, "open ");

  // concatting http if http or https is not already there
  if (memcmp(http, link, 7) != 0 && memcmp(https, link, 8) != 0) {
    strcat(command, http);
  }
  strcat(command, link);  // Append the link

  system(command);  // Opening default web page.
}

// Reads allClasses from .allClasses, and returns a pointer to a list of all the classes
class** readFile() {

  // opening the file
  FILE *theFile = fopen(thePath, "r+");
  if (theFile == NULL) {
    error(1);
  }

  class **allClasses; // A list of all the classes
  allClasses = (class **) malloc(sizeof(class));

  class *nextClass = (class *) malloc(sizeof(class)); //Individual class obj

  int index = 0;
  // Iterating through all the classes in the file, and putting them in allClasses
  while (fread(nextClass, sizeof(class) + sizeof(int) + 2300, 1, theFile)) {

    // Our head node stores our length.
    if (index == 0) {
      allClasses = realloc(allClasses, sizeof(class) * nextClass->len);
    }
    allClasses[index] = nextClass;

    nextClass = (class *) malloc(sizeof(class));
    index++;
  }

  free(nextClass);
  fclose(theFile);
  return allClasses;

}

// Writes all of the structs in this list to .allClasses
// Input: List of all of the classes
void writeFile(class **allClasses) {

  FILE *theFile = fopen(thePath, "w+");
  if (theFile == NULL) {
    error(2);
  }

  // Iterating over the structs and writing earch one to file
  // https://www.geeksforgeeks.org/readwrite-structure-file-c/
  for (int i = 0; i < allClasses[0]->len; i++) {
    if (fwrite(allClasses[i], sizeof(class) + sizeof(int) + 2300, 1, theFile) != 1) {
      printf("failed to write to file");
    } else {
      printf("writing to file\n");
    }
  }
  fclose(theFile);
}

// Freeing pointers.
void freeClasses(class **allClasses) {
  for (int i = 0; i < allClasses[0]->len; i++) {
    free(allClasses[i]);
  }
  free(allClasses);
}

// Prints out the classes
void printAllClasses() {
  class **allClasses = readFile();

  for (int i = 1; i < allClasses[0]->len; i++) {
    printf("====Class %d====\n", i);
    printf("theClass : %s\nsubClass : %s\nlink : %s\n", allClasses[i]->theClass, allClasses[i]->subClass, allClasses[i]->link);
  }
}

// Adds a class to the allClasses file.
// Inputs:
//  String theClass = class->theClass (i.e. Calculus 1)
//  String subClass = class->subClass (i.e. duscussion)
//  String link = class->link (i.e. zoom.com)

void add(char *theClass, char *subClass, char *link) {
  class **allClasses = readFile();

  // head "node" will host the length.
  class *head = allClasses[0];

  // Checking to see if this class is already in our file, removing for now to make my life easier for testing purposes lol
  for (int i = 1; i < head->len; i++) {
    if (strcmp(theClass, allClasses[i]->theClass) == 0 && (strcmp(subClass, allClasses[i]->subClass) == 0)) {
      error(4);
    }
    if (strcmp(link, allClasses[i]->link) == 0) {
      error(5);
    }
  }

  head->len++;

  // Creating the newClass
  class *newClass = (class *) malloc(sizeof(class));
  strcpy(newClass->theClass, theClass);
  strcpy(newClass->subClass, subClass);
  strcpy(newClass->link, link);
  newClass->len = head->len;

  // Inserting newClass to allClasses
  allClasses = realloc(allClasses, sizeof(class) * (head->len));
  allClasses[head->len-1] = newClass;

  // Writing newClass to file and freeing the classes after
  writeFile(allClasses);
  freeClasses(allClasses);

}

// Opening the user inputs website
// Inputs:
//  String theClass = class->theClass
//  String subClass = class->subClass
void openWebsite(char *theClass, char *subClass) {
  class **allClasses = readFile();  // List of all of the classes
  class *newClass;  // The class who's website we want to open.
  for (int i = 1; i < allClasses[0]->len; i++) {
    if ((strcmp(allClasses[i]->theClass, theClass) == 0) && (strcmp(allClasses[i]->subClass, subClass) == 0)) {
      newClass = allClasses[i];
    }
  }
  getWebsite(newClass->link); // Opening up website
  freeClasses(allClasses);
}
