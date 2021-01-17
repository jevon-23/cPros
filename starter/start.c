#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Small program that simply fills in the headers of a file for the type an creates a main if needed for quick
//Start up outside of terminal

//@author Jevon Jackson

//val == 1 == .py file
//val == 2 == .java file
//val == 3 == .c file
void produceStart(char *fileName, int value, int arg, char *argv[]) {
  FILE *theFile = fopen(fileName, "w");
  int placeHold = 0;

  int extra_imports = 1 ? arg == 2 : 0;

  switch(value) {
    case 1: placeHold++; // Python
      char thestr[] = "nothing to do here. Printing this for a reminder everytime that this is not necessary. Delete this line in the file lmao. \n";
      for (int x = 0; thestr[x] != NULL; x++) {
        fputc(thestr[x], theFile);
      }
      break;

    case 2: placeHold++;  // java
      char *str[3];
      str[0] = "public class ";
      str[1] = strtok(fileName, ".");
      str[2] = "{\n  public static void main(String args[]) {\n  }\n}\n";

      for (int x = 0; x < 3; x++) {
        for (int i = 0; str[x][i] != NULL; i++) {
          fputc(str[x][i], theFile);

        }
      }
      break;

    case 3: placeHold++;  // c
      char *theStrs[3];
      theStrs[0] = "#include <stdio.h>\n#include <stdlib.h>\n\n";
      theStrs[1] = "int processCLI(int argc, char **argv, char **filename) {\n  if (argc != 2) {\n    printf(\"usage:\");\n    exit(-1);\n  }\n  return 0;\n}\n";
      theStrs[2] = "int main(int arg, char *argv[]) {\n}\n";

      for (int x = 0; x < 3; x++) {
        for (int i = 0; theStrs[x][i] != NULL; i++) {
          fputc(theStrs[x][i], theFile);
        }
      }
      break;

      case 4: placeHold++; //js
        //currently do not have anything to do for this, so will just create the file


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
    case 'p':
      return 1 ? point[1] == 'y' : -1;

    case 'j': placeHold++;
      char java[] = "java";
      if (strcmp(point, java) == 0) {
        return 2;
      } else {
        return -1;
      }

    case 'c': placeHold++;
      return 3; //Not sure how to check the rest of the string for this rn, cant
      //Use point[1] cause of seg fault, tried using == w "", '', and NULL,
      // '\0', '0', "\0", "0", tried  strcmp
      //Checked the boolean value w a print statement and it was getting back 0. 4 am im kinda sad
      }
  return 0;
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
