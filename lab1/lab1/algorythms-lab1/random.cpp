#include <stdlib.h>

int random(int* arr, int length, int seed) {

	srand(seed);
	for (int i = 0; i < length; i++) {

		arr[i] = rand() % 101;
		
	}
	return 0;
}