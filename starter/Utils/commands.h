#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#include<unistd.h>



struct Commands {
};

int checkFile(int argc, char **argv, char **fileName);
void pyStr(FILE *theFile, int import);
void javaStr(FILE *theFile, char **fileName);
void cStr(FILE *theFile);
void shStr(char **fileName);
void ptStr(FILE *theFile);
void redux();
void rn(FILE *theFile);
void error(char *argv[]);
