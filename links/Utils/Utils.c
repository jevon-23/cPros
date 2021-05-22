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

int init() {
  class *theClass = (class *) malloc(sizeof(class));
  strcpy(theClass->theClass, "Head");
  strcpy(theClass->subClass, "Node");
  theClass->len = 1;

  class **allClasses = (class **) malloc(sizeof(class **));
  allClasses[0] = theClass;
  writeFile(allClasses);
  freeClasses(allClasses);
  return 0;
}

// Opens a the website given from link
// Inputs: link -> the website that we will like to open


int getWebsite(char *link) {
  // If http or https does not begin our website link, it will not open up through system()
  char *http = "http://"; //
  char *https = "https://";

  char command[100];  // What we will be passing in to the system()
  strcpy(command, "open ");

  // concatting http if http or https is not already there
  if (memcmp(http, link, 7) != 0 && memcmp(https, link, 8) != 0) {
    strcat(command, http);
  }
  strcat(command, link);  // Append the link

  system(command);
  return 0;
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


  // Making space for the next class object
  class *nextClass = (class *) malloc(sizeof(class));

  int index = 0;

  // Iterating through all the classes in the file, and putting them in allClasses
  while (fread(nextClass,  sizeof(class) + sizeof(int) + 2300, 1, theFile)) {

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

void writeFile(class **allClasses) {

  FILE *theFile = fopen(thePath, "w+");
  if (theFile == NULL) {
    error(2);
  }

  for (int i = 0; i < allClasses[0]->len; i++) {
    if (fwrite(allClasses[i], sizeof(class) + sizeof(int) + 2300, 1, theFile) != 1) {
      printf("failed to write to file");
    } else {
      printf("writing to file\n");
    }
  }


  fclose(theFile);

}

int freeClasses(class **allClasses) {
  for (int i = 0; i < allClasses[0]->len; i++) {
    free(allClasses[i]);
  }
  free(allClasses);
  return 0;
}

void printAllClasses() {
  class **allClasses = readFile();

  for (int i = 1; i < allClasses[0]->len; i++) {
    printf("====Class %d====\n", i);
    printf("theClass : %s\nsubClass : %s\nlink : %s\n", allClasses[i]->theClass, allClasses[i]->subClass, allClasses[i]->link);
  }
}

int add(char *theClass, char *subClass, char *link) {
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

  allClasses = realloc(allClasses, sizeof(class) * (head->len));  // Making space for the new class being added.
  allClasses[head->len-1] = newClass;

  // Writing newClass to file
  writeFile(allClasses);
  freeClasses(allClasses);

  return 0;
}

int openWebsite(char *theClass, char *subClass) {
  class **allClasses = readFile();
  class *newClass;
  for (int i = 1; i < allClasses[0]->len; i++) {
    if ((strcmp(allClasses[i]->theClass, theClass) == 0) && (strcmp(allClasses[i]->subClass, subClass) == 0)) {
      newClass = allClasses[i];
    }
  }
  getWebsite(newClass->link);
  freeClasses(allClasses);
  return 0;
}
