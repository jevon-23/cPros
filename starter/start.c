#include <stdio.h>
#include <stdlib.h>

//Small program that simply fills in the headers of a file for the type an creates a main if needed for quick
//Start up outside of terminal

//@author Jevon Jackson

// val == 1 == .py file
//val == 2 == .java file
//val == 3 == .c file
void produce(char *fileName, int value) {
  FILE *theFile = fopen(fileName, "w");
  if (value == 1) {
    char thestr[] = "nothing to do here. Printing this for a reminder everytime that this is not necessary. Delete this line in the file lmao. \n";
    for (int x = 0; thestr[x] != NULL; x++) {
      fputc(thestr[x], theFile);
    }
  }
  if (value == 2) {
    char thestr1[] = "public class ";
    for (int x = 0; thestr1[x] != NULL; x++) {
      fputc(thestr1[x], theFile);
    }
    char *point = fileName;
    for (int x = 0; x < 10000; x++) {
      if (point[x] == '.') {
        break;

      }
      fputc(point[x], theFile);
    }
    char thestr2[] = " {\n";
    for (int x = 0; thestr2[x] != NULL; x++) {
      fputc(thestr2[x], theFile);
    }
    char thestr3[] = "  public static void main(String args[]) {\n  }\n}";
    for (int x = 0; thestr3[x] != NULL; x++) {
      fputc(thestr3[x], theFile);
    }
    fputc('\n', theFile);
    return;
  }
    if (value == 3) {
        char thestr2[] = "//This allows us to print\n#include <stdio.h>\n#include <stdlib.h>\n\n";
        for (int x = 0; thestr2[x] != NULL; x++) { //If this doesnt work then we will have to put ">", and fput after
            fputc(thestr2[x], theFile);
        }

    char thestr[] = "int main(int arg, char *argv[]) {\n}\n";
    for (int x = 0; thestr[x] != NULL; x++) {
      fputc(thestr[x], theFile);
    }

    char thestr3[] = "int processCLI(int argc, char **argv, char **filename) {\n  if (argc != 2) {\n    printf(\"usage:\");\n    exit(-1);\n  }\n  return 0;\n}\n";
    for (int x = 0; thestr3[x] != NULL; x++) {
      fputc(thestr3[x], theFile);
    }
  }
  fclose(theFile);
  return;

}

int processCLI(int argc, char **argv, char **filename)
{
if (argc != 2) {
  printf("usage: %s filename\n",argv[0]);
  printf("Pls pass in a file\n");

  exit(-1);
}
  *filename = argv[1];

  int x, suff, thestrcount;
  char p, j, c, per;
  p = 'p';
  j = 'j';
  c = 'c';
  per = '.';
  suff = 0;
  char *point = *filename;
  for (x = 0; x < 10000; x++) {
    if (suff != 0) {
      if (point[x] == p) {
        return 1;
      }
      if (point[x] == j) {
        return 2;
      }
      if (point[x] == c) {
        return 3;
      }
    }
    if (point[x] == per) {
      suff = 1;
    }

  }
  return suff;
}

int main(int arg, char *argv[]) {
  char *file;
  int val;
  val = processCLI(arg, argv, &file);
  if (val == 0) {
    printf("usage: %s filename\n",argv[0]);
    printf("pls pass in a file w type .c, .py, .java");

  }
  produce(file, val);
  printf("process finished");

  return 0;
}
