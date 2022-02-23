#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include "utils/utils.h"


/*
Exits if invalid amount of arguments

if dir is passed in, then we are going to read the entire directory

else we will only be scanning this one file.
*/
int processCLI(int argc, char **argv, char **fileName) {
  if (argc != 2) {
    printf("usage: ./main search ");
    exit(-1);
  }

  *fileName = argv[1];

  checkFile(argc, argv, fileName);
  if (strcmp(argv[1], "dir") == 0) {
    return 1;
  }
  return 0;
}

/*
FIXME:
- When i expand to entire directory, fileContents -> ***, where first pointer points to the files that import fileName / filename.h
  - Head file will filename
*/
int main(int arg, char *argv[]) {
  char *fileName; // The name of the file

  processCLI(arg, argv, &fileName);
  readFile(fileName);
}
