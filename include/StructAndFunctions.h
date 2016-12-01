#ifndef C__GIT_BLITZ_BLITZ_INCLUDE_STRUCTANDFUNCTIONS_H_
#define C__GIT_BLITZ_BLITZ_INCLUDE_STRUCTANDFUNCTIONS_H_
#include "stdlib.h"
struct CNode{
    int data;
    CNode *next;
};
int InvertNumber(int x);
char* MaxCommonPrefix(char** a, int n);
CNode* InvertPairs(CNode* list);
int** SearchPairs(int *a, int n, int sum);
#endif  //  C__GIT_BLITZ_BLITZ_INCLUDE_STRUCTANDFUNCTIONS_H_
