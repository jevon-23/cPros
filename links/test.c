#include <stdio.h>
#include <stdlib.h>
#include "Utils/Utils.h"

void testInit() {
  init();
  printf("completed init");
}

void testRead() {
  testInit();
  class **allClasses = readFile();
  printf("\n after reading file, allClasses[0]->len = %s\n", allClasses[0]->theClass);
  freeClasses(allClasses);
}

void testAdd() {
  init();
  char *newClass = "google";
  char *subClass = "web";
  char *link = "google.com";
  add(newClass, subClass, link);
  class **allClasses = readFile();
  printf("\nallClasses[1]->theClass = %s\n", allClasses[1]->theClass);

  freeClasses(allClasses);
}

void testOpen() {
  init();
  char *newClass = "google";
  char *subClass = "web";
  char *link = "google.com";
  add(newClass, subClass, link);
  openWebsite(newClass, subClass);
}
void testPrint() {
  printAllClasses();
}

int main(int arg, char *argv[]) {
  // testInit();
  // testRead();
  // testAdd();
  // testOpen();
  // testPrint();
}
