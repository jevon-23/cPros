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
    char thestr[] = "nothing to do here.\n";
    for (int x = 0; thestr[x] != '.'; x++) {
      fputc(thestr[x], theFile);
    }
  }
  if (value == 2) {
    char thestr1[] = "public class -";
    for (int x = 0; thestr1[x] != '-'; x++) {
      fputc(thestr1[x], theFile);
    }
    char *point = fileName;
    for (int x = 0; x < 10000; x++) {
      if (point[x] == '.') {
        break;

      }
      fputc(point[x], theFile);
    }
    char thestr2[] = " { \n}";
    for (int x = 0; thestr2[x] != '}'; x++) {
      fputc(thestr2[x], theFile);
    }
    char thestr3[] = "  public static void main(String args[]) {\n  }";
    for (int x = 0; thestr3[x] != '}'; x++) {
      fputc(thestr3[x], theFile);
    }
    fputc('}', theFile);
    fputc('\n', theFile);
    fputc('}', theFile);
    fputc('\n', theFile);


    //We need to save all of the values of the name of the file in order to make a new class, will do this another time
    return;
  }
  if (value == 3) {
    char thestr[] = "int main(int arg, char[] *argv) {\n}";
    for (int x = 0; thestr[x] != '}'; x++) {
      fputc(thestr[x], theFile);
    }
    fputc('}', theFile);
    fputc('\n', theFile);
  }
  fclose(theFile);
  return;

}

int processCLI(int argc, char **argv, char **filename)
{
if (argc != 2) {
  printf("usage: %s filename\n",argv[0]);
  printf("Pls pass in a file\n");
  printf("failed");
  exit(-1);
}
  *filename = argv[1];
  //printf("%c", *filename[0]);
  int x, suff, thestrcount;
  char thestr[4];
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
  //printf("hello");
  return 0;
}
