#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	int n = 0, i = 0;
	double x = 0;
	int* arr;
	FILE* f;
	
	char line[10];

	if (argc < 2)
	{
		printf("Error\n");
		return 1;
	}

	srand(time(NULL));

	printf("--- Program Lab2_2 ---\nThis program reads an array from file and compares the time it takes for different sorting algorithms to sort it.\n");

	f = fopen(argv[1], "r");
	if (!access(argv[1], 0))
		printf("File %s is present.\n", argv[1]);
	else
	{
		printf("File not found. Exiting program.");
		return 1;
	}
	printf("Please choose the sorting algorithm.\nThe temporary array will be reset automatically.\n");

	ScanFile(f, &n, &arr);

	while (1) {
		printf("Enter bubble (b), insertion (i), quick (q) or exit (e): ");
		scanf("%s", line);

		switch (line[0]) {
		case 'b':
			bubblesort(arr, n);
			//Print(n, arr);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'i':
			insertionsort(arr, n);
			//Print(n, arr);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'q':
			quicksort(arr, 0, n - 1);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'e':
			printf("Quit.");
			fclose(f);
			free(arr);
			return 0;
		default:
			printf("Unknown command.\n");
		}
	}
}