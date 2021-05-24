#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#include<unistd.h>
#include <float.h>

typedef struct class {
  char theClass[100];
  char subClass[100];
  char link[2048];
  int len;
} class;

class** readFile();
void writeFile(class **allClasses);
void add(char *theClass, char *subClass, char *link);
void delete(char *theClass, char *subClass);
void openWebsite(char *theClass, char *subClass);
void freeClasses();
void init();
void printAllClasses();
