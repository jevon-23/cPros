//This allows us to print
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Writes imports in to file
int produceJS(char *filename) {
  FILE *file = fopen(filename, "w");
  char *str[2];
  str[0] = "import React, { useState, useEffect } from 'react';\n";
  str[1] = "import { StyleSheet, Text, View, Image, TouchableOpacity } from 'react-native';\n";

  for (int x = 0; x < 2; x++) {
    for (int i = 0; str[x][i] != NULL; i++) {
      fputc(str[x][i], file);
    }
  }
  return 0;
}

// Checks to see if the file has a .js extension
int processCLIJS(int argc, char **argv, char **filename) {
  if (argc != 2) {
    return -1;

}

  // Getting file suffix
  char pointer[100];
  strcpy(pointer, argv[1]);
  char *point = pointer;
  point = strtok(point, ".");
  point = strtok(NULL, ".");

  // Comparing suffix to string
  *filename = argv[1];
  if (strcmp(point, "js") == 0) {
    return 0;
  } else {
    return -1;
  }

}
