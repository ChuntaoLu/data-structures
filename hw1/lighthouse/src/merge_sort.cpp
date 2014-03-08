/*
 * mergesort.cpp
 *
 *  Created on: Mar 7, 2014
 *      Author: lu
 */

void merge(int array[], int lo, int mid, int hi) {
	int* A = array + lo;
	int lb = mid - lo;
	int* B = new int[lb];
	for (int i = 0; i < lb; i++) B[i] = A[i];
	int lc = hi - mid;
	int* C = array + mid;
	for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
		if ((j < lb) && (lc <= k || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (lb <= j || (C[k] < B[j]))) A[i++] = C[k++];
	}
	delete [] B;
}


void mergeSort(int array[], int lo, int hi) {
	if (hi - lo < 2) return;
	int mid = (lo + hi) >> 1;
	mergeSort(array, lo, mid);
	mergeSort(array, mid, hi);
	merge(array, lo, mid, hi);
}
