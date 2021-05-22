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
int add(char *theClass, char *subClass, char *link);
int delete(class *theClass);
int openWebsite(char *theClass, char *subClass);
int freeClasses();
int init();
void printAllClasses();
