#include <stdio.h>
#include <stdlib.h>
#include "Utils/Utils.h"

int processCLI(int argc, char *argv[]) {

  char *commands[5] = {"init", "add", "open", "delete", "print"};

  // If it is init.
  if (argc == 2) {
    if (strcmp(argv[1], commands[0]) == 0) {
      return 0;
    }
    if (strcmp(argv[1], commands[4]) == 0) {
      return 4;
    }
  }
  if (argc != 5 && argc != 4) {
    printf("usage:");
    exit(-1);
  }

// add = 1, open = 2, delete = 3, print = 4
  for (int i = 1; i < 5; i++) {
    if (strcmp(argv[1], commands[i]) == 0) {
      return i;
    }
    // printf("i:argv[i] = %d:%s\n", i, argv[i] );
  }

  return -1;
}


int main(int arg, char *argv[]) {
  int command = processCLI(arg, argv);

  switch(command) {

    case 0: // init()
      init();
      break;

    case 1:
      add(argv[2], argv[3], argv[4]);
      break;

    case 2:
      openWebsite(argv[2], argv[3]);
      break;
    case 3:
      //Not yet implemented
      break;
    case 4:
      printAllClasses();
      break;
    default:
      printf("unknown command\n");
      exit(-1);
  }
  return 0;
}
