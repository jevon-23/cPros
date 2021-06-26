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

  if (argc == 2) {
    if (strcmp(argv[1], "init") == 0) { // If Init
      return 0;
    } else if (strcmp(argv[1], "print") == 0) {     // If print
      return 4;
    } else if (strcmp(argv[1], "help") == 0) {
      return 5;
    }

    return -1;
  }

  char *commands[3] = {"add", "open", "delete"};

// add = 1, open = 2, delete = 3,
  for (int i = 0; i < 3; i++) {
    if (strcmp(argv[1], commands[i]) == 0) {
      checkInputLen(argv[1], argc);
      return i+1;
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
      delete(argv[2], argv[3]); // delete
      break;
    case 4: // print
      printAllClasses();
      break;
    case 5: // help
      printHelp();
    default:
      printf("failing in main\n");
      error(7);
  }
  return 0;
}
