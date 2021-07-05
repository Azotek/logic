#include <stdio.h>
#include <stdlib.h>

int summs(int**& arr, int rows, int cols) {
	int* summr = (int*)calloc(rows, sizeof(int));
	int* summc = (int*)calloc(cols, sizeof(int));
	for (int i = 0; i < cols; i++) {

		summc[i] = 0;
	}
	for (int i = 0; i < rows; i++) {

		summr[i] = 0;
	}
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			summr[i] += arr[i][j];
			summc[j] += arr[i][j];
		}
	}
	printf("Сумма по строкам: ");
	for (int i = 0; i < rows; i++) {

		printf("%d ", summr[i]);
	}
	printf("\n");
	printf("Сумма по столбцам: ");
	for (int i = 0; i < cols; i++) {

		printf("%d ", summc[i]);
	}
	printf("\n");
	return 0;
}