#include <stdlib.h>

int* makearr(int size) {

	return (int *) calloc(size, sizeof(int));

}