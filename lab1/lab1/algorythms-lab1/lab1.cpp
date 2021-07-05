#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "lab1.h"

#define LENGTH 8
#define ROWS 3
#define COLS 4

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int mas_size;
	for (int i = 0; i < 10; i++) {

		printf("%d ", a[i]);
	}
	printf("Разность между мин. и макс. элементом равна %d.\n", diff(a, 10));
	int mas[LENGTH];
 	random(mas, LENGTH, time(0));
	for (int i = 0; i < LENGTH; i++) {

		printf("%d ", mas[i]);
	}
	printf("\n");
	printf("Введите размер создаваемого массива: ");
	scanf("%d", &mas_size);
	printf("\n");
	int* dynarr = makearr(mas_size);
	random(dynarr, mas_size, time(0) + 1);
	for (int i = 0; i < mas_size; i++) {

		printf("%d ", dynarr[i]);
	}
	printf("\n\n");
	int** rectarr = (int**)calloc(ROWS, sizeof(int*));
	for (int i = 0; i < ROWS; i++) {

		rectarr[i] = (int*)calloc(COLS, sizeof(int));
		random(rectarr[i], COLS, time(0) + i + 2);
		for (int j = 0; j < COLS; j++) {

			printf("%d\t", rectarr[i][j]);
		}
		printf("\n");
	}
	summs(rectarr, ROWS, COLS);
	eios();
	_getch();
}
