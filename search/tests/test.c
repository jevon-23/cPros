#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include "../utils/utils.h"


void testRead() {

  printf("running the test\n");
  aFile theFile = readFile("help.c");
  printf("fileName = %s\n", theFile.name);
  for (int i = 0; i < theFile.lineCount; i++) {
    printf("%s", *(theFile.contents +i));
  }

  aFunc *theVals = CfindFuncs(&theFile);
  printf("theVals->numFuncs = %d\n", theVals->numFuncs);
  for (int i = 0; i < theVals->numFuncs; i++) {
    // printf("hello world\n");
    // printf("i = %d, start @ %d, numLines = %d\n", i, (theVals + i)->start, (theVals + i)->numLines);
  }
}
int main(int arg, char *argv[]) {
  testRead();
  return 0;
}
