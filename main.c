#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <math.h>
#include <string.h>

// File Initialization
FILE *gInputFile;
void usage (char *);

// Get file input
const int kMaxStringLength = 1000;
bool getStrings (char [kMaxStringLength], char [kMaxStringLength]);

int main(int argc, char *argv[]) {
  /*-------------------------------FILE INITIALIZATION START-----------------------------*/
  if (argc != 2) usage (argv[0]);

  if (NULL == (gInputFile = fopen(argv[1], "r"))) {
    fprintf (stderr, "inputFile: %s: %s\n", argv[1], strerror(errno));
    exit (EXIT_FAILURE);
  }
  else {
    fprintf (stderr, "%s opened for reading.\n\n" , argv[1]);
  }
  /*-------------------------------FILE INITIALIZATION END--------------------------------*/
  /*--------------------------------MAIN PROGRAM START------------------------------------*/

  char str1 [kMaxStringLength], str2 [kMaxStringLength];
  
  while (getStrings(str1, str2)) {
    printf ("str1 : %s\nstr2 : %s\n\n", str1, str2);
  }






  
  /*--------------------------------MAIN PROGRAM END--------------------------------------*/
  /*--------------------------------FILE CLEANUP START------------------------------------*/
  fclose (gInputFile);
  /*--------------------------------FILE CLEANUP END--------------------------------------*/
  return 0;
}

// File Initialization
void usage (char *cmd) {
  fprintf (stderr, "usage: %s inputFileName\n", cmd);
  exit (EXIT_SUCCESS);
}

// Get file input
bool getStrings (char str1 [kMaxStringLength], char str2 [kMaxStringLength]) {
  if (fgets (str1, kMaxStringLength, gInputFile) == NULL) return false;
  if (fgets (str2, kMaxStringLength, gInputFile) == NULL) return false;
  
  str1[strcspn(str1, "\n")] = 0;
  str2[strcspn(str2, "\n")] = 0;
  return true;
}