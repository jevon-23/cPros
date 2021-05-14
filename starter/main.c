#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#include<unistd.h>
#include "Utils/commands.h"

// Checks to make sure that we have an actual file.
// Returns the number correleating with this .extension/import.
// Can see the the correlation in main.
int processCLI(int argc, char **argv, char **filename) {

  if (argc != 2 && argc != 3) {
    printf("Incorrect number of arguments.");
    return -1;
}
  int fileNum; // the value that we will be using to determine what kind of file we are dealing with.

  // Lazy code. Basically mapping each import to a num without using some type of actual mapping. mayve ill clean this up later.
    char *imports[] = {"pt", "redux", "rn"};
    int importNums[] = {5, 6, 7}; // {pt, redux, react-native}

    // If we are dealing with an import, we cannot make it based on the fileName. and we are not shortcircuting.
    for (int i = 0; i < 3; i++) {
      if (strcmp(imports[i], argv[2]) == 0) {
        if (i != 1) { // if not redux
          *filename = argv[1];
          fileNum = checkFile(argc, argv, filename);
        }
        return importNums[i] ? fileNum != -1 : -1 ;
      }
    }

  *filename = argv[1];
  fileNum = checkFile(argc, argv, filename);
  printf("\nfileNum = %d", fileNum);
  return fileNum;
}

// usage/ inputs:
// 1. {filename} | 2. {import} {fileName}  (takes in singular import at the moment)
// check ReadMe for how it exactly works

int main(int arg, char *argv[]) {
 char *file;  // The file Name
 int val; // Value correlating with .extension type
 printf("hello world");

 val = processCLI(arg, argv, &file);
 if (val == -1) {
   error(argv);

   // error(argv);
 }

 FILE *theFile = fopen(file, "w");
 printf("\n%d", val);

 switch(val) {
   case 1:
     // pyStr(theFile, import)
    break;

  case 2:
      javaStr(theFile, &file);  // java
      break;

  case 3:
      cStr(theFile); // c
      break;

  case 4:
    shStr(&file); // sh
    break;

  case 5:
    pyStr(theFile, val); // pt
    break;

  case 6:
    redux(); // redux
    break;

  case 7:
    rn(theFile); // react-native
    break;

   default :
     error(argv);
     exit(-1);
 }

 printf("process finished\n");

 return -1;

}