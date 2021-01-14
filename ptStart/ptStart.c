#include <stdio.h>
#include <stdlib.h>

// @author Jevon Jackson

// val == 1 == .py file
//val == 2 == .java file
//val == 3 == .c file

void process(char *filename) {
  FILE *theFile = fopen(filename, "w");
  char thestr[] =  "import torch\nimport torch.nn as nn\nimport torch.nn.functional as F\nimport torch.optim as optim\nimport torchvision\nimport numpy as np\nclass Net(nn.Module):\n    def __init__(self):\n        super(Net, self).__init__()\n\n    def forward(self, x):\n        #fill in\n        x = 1\n";
  for (int x = 0; thestr[x] != NULL; x++) {
    fputc(thestr[x], theFile);
  }
  fclose(theFile);
}

int processCLI(int argc, char ** argv, char ** filename) {
  if (argc != 2) {
    printf("usage: %s filename\n",argv[0]);
    printf("Pls pass in a file\n");
    exit(-1);
  }

  *filename = argv[1];
  int sufc = 0;
  char p = 'p';
  char y = 'y';
  char per = '.';
  char *point = *filename;

  for (int x = 0; x < 100; x++) {
    if (sufc == 0 && point[x] == per) {
      sufc++;
    }
    if (sufc == 1 && point[x] == p) {

      sufc++;
    }
    if (sufc == 2 && point[x] == y) {
      sufc++;
      return 1;
    }
  }
  return -1;
}

int main(int arg, char *argv[]) {
  char* file;
  int val = processCLI(arg, argv, &file);

  if (val == -1) {
    printf("usage: %s filename\n",argv[0]);
    printf("pls pass in a file w type .py,");
    return -1;
    }

  process(file);

  printf("finished process");

  return 0;
}
