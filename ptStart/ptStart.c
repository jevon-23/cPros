#include <stdio.h>
#include <stdlib.h>

// @author Jevon Jackson

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
    return -1;
  }

  *filename = argv[1];
  int sufc = 0;
  int failed = 0;
  char *point = argv[1];

//If i ever come back to this, please remember that there is actually a string.split in c,
//Using it inside of start.c for reference if needed
  for (int x = 0; point[x] != NULL; x++) {
    switch(point[x]) {
      case '.':
        sufc++;
        break;

      case 'p':
        if (sufc != 0) {
          sufc++ ? sufc == 1 : failed++;
        }
        break;

      case 'y':
        if (sufc != 0) {
          sufc++ ? sufc == 2 : failed++;
        }
        break;
    }

    if (sufc == 3 || failed) {
      break;
    }
  }

  if (sufc != 3 || failed) {
    return -1;
  }
  return 0;
}

int main(int arg, char *argv[]) {
  char* file;
  int val = processCLI(arg, argv, &file);

  if (val == -1) {
    printf("usage: %s filename\n",argv[0]);
    printf("pls pass in a file w type .py.\n");
    exit(-1);
    }

  process(file);
  printf("finished process\n");
  return 0;
}
