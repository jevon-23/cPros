//This allows us to print
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int putFiles() {
  int dir = mkdir("./redux", 0777);
  if (dir != 0) {
    printf("could not create directory");
    return -1;
  };
  char *files[5] = {"./redux/action.js", "./redux/index.js", "./redux/reducer.js", "./redux/actionTypes.js", "./redux/store.js"};
  for (int x = 0; x <= 4; x++) {
    FILE *act = fopen(files[x], "w");
    fclose(act);
  }
  return 0;
}

int processCLI(int argc, char **argv) {
  if (argc != 1) {
    printf("Usage: \'redux\'\n");
    printf("This will produce the files needed to use redux in a react-native project.\nIncludes action, actionTypes, index, reducer, and store");
    exit(-1);
  }
  return 0;
}

int main(int arg, char *argv[]) {
  int val = processCLI(arg, argv);

  if (val != 0) {
    printf("Unable to make files for some reason");
  }

  putFiles();
}
