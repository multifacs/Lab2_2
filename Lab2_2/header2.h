#ifndef _HEADER2_H_
#define _HEADER2_H_
#include <stdio.h>

void Print(int size, int* m);
void ScanFile(FILE* f, int* size, int** m);
void insertionsort(int* arr, int n);
void quicksort(int* arr, int first, int last);
void qs(int* s_arr, int first, int last);
void bubblesort(int* a, int n);

#endif