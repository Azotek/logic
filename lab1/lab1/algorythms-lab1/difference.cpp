

int diff(int* arr, int length) {

	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	return (max-min);
}