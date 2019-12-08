#ifndef _HEADER2_H_
#define _HEADER2_H_
#include <stdio.h>

void Print(int size, double* m);
void ScanFile(FILE* f, int* size, double** m);
void insertionsort(double* arr, int n);
void quicksort(double* arr, int first, int last);
//void qs(double* s_arr, int first, int last);
void qs(double* Arr, int first, int last);
void bubblesort(double* a, int n);

#endif