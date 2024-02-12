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

// Common Permutation
const int kNumLettersInAlphabet = 26;
int gStr1Chars [kNumLettersInAlphabet] = { 0 };
int gStr2Chars [kNumLettersInAlphabet] = { 0 };
char gPermutation [kMaxStringLength];
int numChars (char *, char);
void getNumChars (char *, char *);
void printNumChars (int *, int *);
void getPermutation (int *, int *);
void printPermutation (char *);


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
    printf ("str1 : %s\nstr2 : %s\n", str1, str2);
    getNumChars(str1, str2);
    //printNumChars(gStr1Chars, gStr2Chars);
    getPermutation(gStr1Chars, gStr2Chars);
    printPermutation (gPermutation);
    printf ("\n");
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

// Common Permutation
int numChars (char *str, char c) {
  int num = 0;
  for (int i = 0; *(str + i) != '\0'; i++) {
    if (*(str + i) == c) num++;
  }
  return num;
}
void getNumChars (char *str1, char *str2) {
  for (int i = 0; i < kNumLettersInAlphabet; i++) {
    gStr1Chars[i] = numChars(str1, 'a' + i);
    gStr2Chars[i] = numChars(str2, 'a' + i);
  }
}
void printNumChars (int *str1, int *str2) {
  printf ("char str1 str2 min\n");
  printf ("---- ---- ---- ---\n");
  for (int i = 0; i < kNumLettersInAlphabet; i++) {
    printf ("%4c %4d %4d %3d\n", 'a' + i, str1[i], str2[i], str1[i] < str2[i] ? str1[i] : str2[i]);
  }
  printf ("\n");
}
void getPermutation (int *str1, int *str2) {
  int permutationIndex = 0;
  for (int i = 0; i < kNumLettersInAlphabet; i++) {
    // Get min
    int min = INT_MAX;
    if (str1[i] < str2[i]) min = str1[i];
    else if (str1[i] > str2[i]) min = str2[i]; 
    else min = str1[i];

    for (; min > 0; min--) {
      gPermutation [permutationIndex] = 'a' + i;
      permutationIndex++;
    }
  }
}
void printPermutation (char *permutation) {
  printf ("permutation: %s\n", permutation);
}