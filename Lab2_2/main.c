#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	int n = 0, i = 0;
	int* arr;
	FILE* f;

	char line[10];

	if (argc < 2)
	{
		printf("Error\n");
		return 1;
	}

	srand(time(NULL));

	f = fopen(argv[1], "a+");
	ScanFile(f, &n, &arr);

	while (1) {
		printf("Enter bubble, insertion, quick or exit: ");
		//fgets(line, sizeof(line), stdin);
		scanf("%s", line);

		switch (line[0]) {
		case 'b':
			bubblesort(arr, n);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'i':
			insertionsort(arr, n);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'q':
			quicksort(arr, 0, n - 1);
			free(arr);
			ScanFile(f, &n, &arr);
			break;
		case 'e':
			printf("Quit");
			fclose(f);
			free(arr);
			return 0;
		default:
			printf("Sosi\n");
		}
	}
}