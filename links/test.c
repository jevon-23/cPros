#include <stdio.h>
#include <stdlib.h>
#include "Utils/Utils.h"

void testInit() {
  init();
  printf("completed init");
}

void testRead() {
  testInit();
  class **allClasses = readFile(0);
  printf("\n after reading file, allClasses[0]->len = %s\n", allClasses[0]->theClass);
  freeClasses(allClasses);
}

void testAdd() {
  init();
  char *newClass = "google";
  char *subClass = "web";
  char *link = "google.com";
  add(newClass, subClass, link);
  class **allClasses = readFile(0);
  printf("\nallClasses[1]->theClass = %s\n", allClasses[1]->theClass);

  freeClasses(allClasses);
}

void testOpen() {
  init();
  char *newClass = "google";
  char *subClass = "web";
  char *link = "google.com";
  add(newClass, subClass, link);
  openWebsite(newClass, subClass, false);
}
void testPrint() {
  printAllClasses(0);
}

void testDelete() {
  system("./cMain.sh");
}

void testHelp() {
  printHelp();
}

void testOpenGroup() {
  init();
  char *startPack = "startPack";
  char **links = (char **) malloc(sizeof(char *) * 2);
  *links = "google.com";
  *(links+1) = "reddit.com";
  printf("links[0] = %s, links[1] = %s", *links, *(links+1));

  addGroup(startPack, links, 2);
  openWebsite(startPack, "", true);

  free(links);
}
int main(int arg, char *argv[]) {
  // testInit();
  // testRead();
  // testAdd();
  // testOpen();
  // testPrint();
  // testDelete();
  // testHelp();
  // testOpenGroup();
}
