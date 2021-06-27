#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#include<unistd.h>
#include "commands.h"
#include <sys/stat.h>

int checkFile(int argc, char **argv, char **fileName) {
  char pointer[100];  // a copy of the filename that we will traverse through
  strcpy(pointer, *fileName);
  char *point = pointer;

  // Shifting the pointer over to the .extension of the file
  point = strtok(point, ".");
  point = strtok(NULL, ".");

  char *types[] = {"py", "java", "c", "sh", "go"};

  for (int i = 0; i < 5; i++) {
    if (strcmp(point, types[i]) == 0) {
      return i;
    }
  }
  return -1;
}

// .go package, alongside importing fmt and strings
void goStr(FILE *theFile, char **fileName) {
  char *goStrs[3];
  goStrs[0] = "package ";
  goStrs[1] = strtok(*fileName, ".");
  goStrs[2] = "\n\nimport (\n\t\"fmt\"\n\"\tstrings\"\n)";

  for (int x = 0; x < 3; x++) {
    for (int i = 0; goStrs[x][i] != '\0'; i++) {
      fputc(goStrs[x][i], theFile);
    }
  }
}
// .py imports. As of right now only takes in pytorch
void pyStr(FILE *theFile, int import) {

  //pyTorch
  if (import == 5) {
    char thestr[] =  "import torch\nimport torch.nn as nn\nimport torch.nn.functional as F\nimport torch.optim as optim\nimport torchvision\nimport numpy as np\nclass Net(nn.Module):\n    def __init__(self):\n        super(Net, self).__init__()\n\n    def forward(self, x):\n        #fill in\n        x = 1\n";
    for (int x = 0; thestr[x] != '\0'; x++) {
      fputc(thestr[x], theFile);
    }
    fclose(theFile);
    }
  }

// .java
void javaStr(FILE *theFile, char **fileName) {
  char *javaStrs[3];
  javaStrs[0] = "public class ";
  javaStrs[1] = strtok(*fileName, ".");
  javaStrs[2] = " {\n  public static void main(String args[]) {\n  }\n}\n";

  for (int x = 0; x < 3; x++) {
    for (int i = 0; javaStrs[x][i] != '\0'; i++) {
      fputc(javaStrs[x][i], theFile);
    }
  }

}

// .c files
void cStr(FILE *theFile) {
  char *cStrs[3];
  cStrs[0] = "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <float.h>\n#include <stdbool.h>\n\n";
  cStrs[1] = "int processCLI(int argc, char **argv, char **filename) {\n  if (argc != 2) {\n    printf(\"usage:\");\n    exit(-1);\n  }\n  return 0;\n}\n";
  cStrs[2] = "int main(int arg, char *argv[]) {\n}\n";

  for (int x = 0; x < 3; x++) {
    for (int i = 0; cStrs[x][i] != '\0'; i++) {
      fputc(cStrs[x][i], theFile);
    }
  }
}

// .sh
void shStr(char **fileName) {
  char shArgs[100];
  strcpy(shArgs,"~/programs/cpros/starter/Utils/sh_helper/helps.sh ");
  system(strcat(shArgs, *fileName));
}

// redux import for react
void redux() {
  int dir = mkdir("./redux", 0777);
  if (dir != 0) {
    printf("could not create directory");
    return;
  };

  char *files[5] = {"./redux/action.js", "./redux/index.js", "./redux/reducer.js", "./redux/actionTypes.js", "./redux/store.js"};
  for (int x = 0; x <= 4; x++) {
    FILE *act = fopen(files[x], "w");
    fclose(act);
  }
}

// react native
void rn(FILE *theFile) {
  char *str[2];
  str[0] = "import React, { useState, useEffect } from 'react';\n";
  str[1] = "import { StyleSheet, Text, View, Image, TouchableOpacity } from 'react-native';\n";

  for (int x = 0; x < 2; x++) {
    for (int i = 0; str[x][i] != '\0'; i++) {
      fputc(str[x][i], theFile);
    }
  }
}

// error
void error(char *argv[]) {
  printf("usage: %s {filename}\n",argv[0]);
  printf("usage: %s {fileName} {pt/redux/rn} \n", argv[0]);
  printf("pls pass in a file w type .c, .py, .java. pt = pyTorch, redux = redux, rn = react-native,\n\tgolang = .go\n");
  exit(-1);
}
