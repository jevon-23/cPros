#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#include<unistd.h>

//Small program that simply fills in the headers of a file for the type an creates a main if needed for quick
//Start up outside of terminal

//@author Jevon Jackson

//val == 1 == .py file
//val == 2 == .java file
//val == 3 == .c file
//val == 4 == .sh file
void produceStart(char *fileName, int value, int arg, char *argv[]) {
  FILE *theFile = fopen(fileName, "w");
  int placeHold = 0;

  switch(value) {
    case 1: placeHold++; // Python
      char pyStr[] = "Will soon implement it so that it will instead take in a library, and we will input the imports to FILENAME \n";
      for (int x = 0; pyStr[x] != NULL; x++) {
        fputc(pyStr[x], theFile);
      }
      break;

    case 2: placeHold++;  // java
      char *javaStrs[3];
      javaStrs[0] = "public class ";
      javaStrs[1] = strtok(fileName, ".");
      javaStrs[2] = "{\n  public static void main(String args[]) {\n  }\n}\n";

      for (int x = 0; x < 3; x++) {
        for (int i = 0; javaStrs[x][i] != NULL; i++) {
          fputc(javaStrs[x][i], theFile);

        }
      }
      break;

    case 3: placeHold++;  // c
      char *cStrs[3];
      cStrs[0] = "#include <stdio.h>\n#include <stdlib.h>\n\n";
      cStrs[1] = "int processCLI(int argc, char **argv, char **filename) {\n  if (argc != 2) {\n    printf(\"usage:\");\n    exit(-1);\n  }\n  return 0;\n}\n";
      cStrs[2] = "int main(int arg, char *argv[]) {\n}\n";

      for (int x = 0; x < 3; x++) {
        for (int i = 0; cStrs[x][i] != NULL; i++) {
          fputc(cStrs[x][i], theFile);
        }
      }
      break;

      case 4: placeHold++; // .sh

        // You cannot write directly to a .sh file, so insteade we are calling a .sh file that writes in the #!bin/zsh into my file.
        // Going to update this later because im just procastinating studying for my last final lmao
        // But if somebody random is using this before it is updated, a potential error is trying to run this with a differernt bash than zsh
        // Sorry macos made me do it lol

        char shArgs[100];
        strcpy(shArgs,"~/programs/cpros/starter/sh_helper/helps.sh ");
        system(strcat(shArgs, fileName));

        break;
  }
}

int processCLIStart(int argc, char **argv, char **filename)
{
if (argc != 2) {
  return -1;
}
  *filename = argv[1];

  int placeHold = 0;

  char pointer[100];
  strcpy(pointer, argv[1]);
  char *point = pointer;
  point = strtok(point, ".");
  point = strtok(NULL, ".");

  switch(point[0]) {
    case 'p':  // .py
      return 1 ? point[1] == 'y' : -1;

    case 'j': placeHold++;  // .java
      char java[] = "java";
      if (strcmp(point, java) == 0) {
        return 2;
      } else {
        return -1;
      }

    case 'c': placeHold++;  // .c
      return 3;

    case 's': placeHold++; // .sh
      return 4;

    default :
      return -1;
    }

}

int main(int arg, char *argv[]) {
  char *file;
  int val;
  val = processCLIStart(arg, argv, &file);
  if (val == -1) {
    printf("usage: %s filename\n",argv[0]);
    printf("pls pass in a file w type .c, .py, .java\n");
    exit(-1);
  }
  produceStart(file, val, arg, argv);
  printf("process finished\n");

  return 0;
}
