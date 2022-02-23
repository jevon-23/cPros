/*
A function. Points to the
*/
typedef struct aFunc {
  char *name; // Name of func
  int start; // What line func is on
  int numLines; // How long the function is
  int numFuncs; // If in a list, how many other funcs are there (only applicable to head maybe)
} aFunc;


/*
Just a mapping between the name of a file and the contents that file holds just to make my life a little easier in the future
Going to make all of these, the head of the list will always be the the file that we are running search on
*/
typedef struct aFile {
  char *name; // Name of file
  char **contents; // Contents in file
  int lineCount; // How long is the file
} aFile;

aFunc* findFuncs(aFile *theFile);
int checkFile(int argc, char **argv, char **fileName);
aFile readFile(char *filename);
void formatFile(aFile *theFile);
void freeFiles(aFile *allFiles);
aFunc* CfindFuncs(aFile *theFile);
