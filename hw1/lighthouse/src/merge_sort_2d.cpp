/*
 * mergesort2d.cpp
 *
 *  Created on: Mar 7, 2014
 *      Author: lu
 */
void merge2d(int array[][2], int lo, int mid, int hi) {
	int (*A)[2] = array + lo;
	int lb = mid - lo;
	int (*B)[2] = new int[lb][2];
	for (int i = 0; i < lb; i++) {
		B[i][0] = A[i][0];
		B[i][1] = A[i][1];
	}
	int lc = hi - mid;
	int (*C)[2] = array + mid;
	for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
		if ((j < lb) && ((lc <= k) || (B[j][0] <= C[k][0]))) {
			A[i][0] = B[j][0];
			A[i++][1] = B[j++][1];
		}
		if ((k < lc) && ((lb <= j) || (C[k][0] < B[j][0]))) {
			A[i][0] = C[k][0];
			A[i++][1] = C[k++][1];
		}
	}
	delete [] B;
}

void mergeSort2d(int array[][2], int lo, int hi) {
	if (hi - lo < 2) return;
	int mid = (lo + hi) >> 1;
	mergeSort2d(array, lo, mid);
	mergeSort2d(array, mid, hi);
	merge2d(array, lo, mid, hi);
}




