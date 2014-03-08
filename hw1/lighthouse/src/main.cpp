#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "binary_search.h"


long countCrossPairs(int array[][2], int lo, int mid, int hi) {
	int (*leftHalf)[2] = array + lo;
	int (*rightHalf)[2] = array + mid;
	int ll = mid - lo;
	int lr = hi - mid;
	int* rightY = new int[lr];
	for (int i = 0; i < lr; i++) rightY[i] = rightHalf[i][1];
	mergeSort(rightY, 0, lr);
	long crossPairs = 0;
	for (int i = 0; i < ll; i++) {
		crossPairs += lr - binarySearch(rightY, leftHalf[i][1], 0, lr) - 1;
	}
	delete [] rightY;
	return crossPairs;
}


long countPairs(int array[][2], int lo, int hi) {
	if (hi - lo < 2) return 0;
	int mid = (lo + hi) >> 1;
	long left = countPairs(array, lo, mid);
	long right = countPairs(array, mid, hi);
	long cross = countCrossPairs(array, lo, mid, hi);
	return left + right + cross;
}


void lightHouse() {
	int arrayLength;
	scanf("%d", &arrayLength);
	int (*array)[2] = new int[arrayLength][2];
	for (int i = 0; i < arrayLength; i++) {
		scanf("%d %d", &array[i][0], &array[i][1]);
	}
	mergeSort2d(array, 0, arrayLength);
	long pairs = countPairs(array, 0, arrayLength);
	printf("%ld\n", pairs);
}


void testLighthouse() {
	clock_t begin = clock();

	int al = 1000000;
	int cordMax = 10000000;
	srand(time(NULL));
	int (*testArray)[2] = new int[al][2];
	for (int i = 0; i < al; i++) {
		testArray[i][0] = rand() % cordMax + 1;
		testArray[i][1] = rand() % cordMax + 1;
	}
	mergeSort2d(testArray, 0, al);
	long pairs = countPairs(testArray, 0, al);
	printf("%ld\n", pairs);

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", elapsed_secs);
}


int main() {
//	testLighthouse();
	lightHouse();
	return 0;
}
