#include <stdio.h>
#include <stdlib.h>
#include "Utils/Utils.h"

// Checking arguments, and determing the command given to us
// Inputs :
//  argc = num input args from STDIN
//  argv = the input arguments from STDIN
//
// outputs :
//  int command : integer mapped to command, which is either
//    init = 0, add = 1, open = 2, delete = 3, print = 4
int processCLI(int argc, char *argv[]) {

  char *commands[5] = {"init", "add", "open", "delete", "print"};

  if (argc == 2) {
      // If Init
    if (strcmp(argv[1], commands[0]) == 0) {
      return 0;
    }
    // If print
    if (strcmp(argv[1], commands[4]) == 0) {
      return 4;
    }
    return -1;
  }

  if (argc != 5 && argc != 4) {
    printf("usage:");
    exit(-1);
  }

// add = 1, open = 2, delete = 3,
  for (int i = 1; i < 4; i++) {
    if (strcmp(argv[1], commands[i]) == 0) {
      return i;
    }
  }

  return -1;
}


int main(int arg, char *argv[]) {
  int command = processCLI(arg, argv);

  switch(command) {

    case 0: // init()
      init();
      break;
    case 1: // Add
      add(argv[2], argv[3], argv[4]);
      break;
    case 2: // Open
      openWebsite(argv[2], argv[3]);
      break;
    case 3:
      delete(argv[2], argv[3]);
      break;
    case 4: // print
      printAllClasses();
      break;
    default:
      printf("unknown command\n");
      exit(-1);
  }
  return 0;
}
