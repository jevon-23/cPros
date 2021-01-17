#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// @author Jevon Jackson

// Input data into the file
void producePT(char *filename) {
  // Opening the file and putting the imports into it.
  FILE *theFile = fopen(filename, "w");
  char thestr[] =  "import torch\nimport torch.nn as nn\nimport torch.nn.functional as F\nimport torch.optim as optim\nimport torchvision\nimport numpy as np\nclass Net(nn.Module):\n    def __init__(self):\n        super(Net, self).__init__()\n\n    def forward(self, x):\n        #fill in\n        x = 1\n";
  for (int x = 0; thestr[x] != NULL; x++) {
    fputc(thestr[x], theFile);
  }
  fclose(theFile);
}

// Checks to see if the file that is passed in is of type .py
// If it is, outputs 0 , otherwise outputs -1
int processCLI(int argc, char ** argv, char ** filename) {

    if (argc != 2) {
    return -1;
  }

  *filename = argv[1];  // Putting the filename into the 'filename' pointer

  // Getting the dot extension of the file. Checking to make sure that it is .py
  char pointer[100];
  strcpy(pointer, argv[1]);
  char *point = pointer;
  point = strtok(point, ".");
  point = strtok(NULL, ".");

  // strcmp does not like one lined if statements, or i just dont know hwo to write them
  if (strcmp(point, "py") == 0) {
    return 0;
  } else {
    return -1;
  }


}

//Runs processCLI to make sure this is of the right dot extnesion.
//Then runs process to write in to the file the imports and the basic set up of a nn
int main(int arg, char *argv[]) {
  char* file;
  int val = processCLI(arg, argv, &file); // Checking for file type
  if (val == -1) {
    printf("\nusage: %s filename\n",argv[0]);
    printf("pls pass in a file w type .py.\n");
    exit(-1);
    }

  producePT(file);
  printf("finished process\n");
  return 0;
}
