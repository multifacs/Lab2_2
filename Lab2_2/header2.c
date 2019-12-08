#include "header2.h"
#include <stdlib.h>
#include <time.h>

#pragma warning(disable : 4996)

#define SWAP(A, B) { A = A + B; B = A - B; A = A - B; }


void Print(int size, double* m)
{
	int i = 0;
	printf("N = %d\n", size);
	for (i = 0; i < size; i++)
		printf("m[%d] = %lf\n", i, m[i]);
}

void ScanFile(FILE* f, int* size, double** m)
{
	int i = 0, j = 0;
	rewind(f);
	fscanf(f, "%d\n", size);
	*m = (double*)malloc(*size * sizeof(double));
	for (i = 0; i < *size; i++)
		fscanf(f, "m[%d] = %lf\n", &j, &((*m)[i]));
}

void insertionsort(double* arr, int n)
{
	int i, key, j;

	clock_t start, stop;

	start = clock();

	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

	stop = clock();

	printf("Sort required %.3lf seconds\n", (double)(stop - start) / CLK_TCK);
}

void quicksort(double* arr, int first, int last)
{
	clock_t start, stop;

	start = clock();

	qs(arr, first, last);

	stop = clock();

	printf("Sort required %.3lf seconds\n", (double)(stop - start) / CLK_TCK);
}

void qs(double* s_arr, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2];
		do
		{
			while (s_arr[left] < middle) left++;
			while (s_arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = s_arr[left];
				s_arr[left] = s_arr[right];
				s_arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}

void bubblesort(double* a, int n)
{
	int j, nn;

	clock_t start, stop;

	start = clock();

	do {
		nn = 0;
		for (j = 1; j < n; ++j)
			if (a[j - 1] > a[j]) {
				SWAP(a[j - 1], a[j]);
				nn = j;
			}
		n = nn;
	} while (n);

	stop = clock();

	printf("Sort required %.3lf seconds\n", (double)(stop - start) / CLK_TCK);
}