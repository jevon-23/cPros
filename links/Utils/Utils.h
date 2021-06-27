#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<string.h>
#include<unistd.h>
#include <float.h>

typedef struct class {
  char theClass[100]; // Name of the class
  char subClass[100];
  char link[2048];
  int len;
} class;

class** readFile();
void writeFile(class **allClasses);
void add(char *theClass, char *subClass, char *link, bool group);
void addGroup(char *theClass, char **theLinks, int theLinksLen);
void delete(char *theClass, char *subClass);
void openWebsite(char *theClass, char *subClass, bool group);
void openWebsiteGroup(char *theClass);
void freeClasses();
void init();
void printAllClasses();
void checkInputLen(char *theInput, int argc, char *numGroups);
void printHelp();
void error();
