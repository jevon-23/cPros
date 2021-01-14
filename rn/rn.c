//This allows us to print
#include <stdio.h>
#include <stdlib.h>

void produce(char *filename) {
  FILE *file = fopen(filename, "w");
  char *str[2];
  str[0] = "import React, { useState, useEffect } from 'react';\n";
  str[1] = "import { StyleSheet, Text, View, Image, TouchableOpacity } from 'react-native';\n";

  for (int x = 0; x < 2; x++) {
    for (int i = 0; str[x][i] != NULL; i++) {
      fputc(str[x][i], file);
    }
  }
}

void processCLI(int argc, char **argv, char **filename) {
  if (argc != 2) {
    printf("usage: %s filename", argv[0]);
    exit(-1);
  }
  char *file = argv[1];
  char per = '.';
  char j = 'j';
  char s = 's';
  int counter = 0;
  int failed = 0;
  for (int x = 0; file[x] != NULL; x++) {
    switch(file[x]) {
      case '.':
        printf("hit0, %c", file[x]);
        counter++;
        break;
      case 'j':
        if (counter == 0) {
          break;
        }
        counter++ ? counter == 1 : failed++;
        break;
      case 's':
      if (counter == 0) {
        break;
      }
        counter++ ? counter == 2 : failed++;
        break;
    }
    if (counter == 3) {
      break;
    }


  }
  printf("counter = %d\n", counter);
  if (failed != 0 || counter != 3) {
    printf("please pass in file of type .js, counter = %d, failed = %d", counter, failed);
    exit(-1);
  }
  *filename = argv[1];

}
int main(int arg, char *argv[]) {
  char *filename;
  processCLI(arg, argv, &filename);

  produce(filename);
  printf("process finished\n");
  return 0;
}
