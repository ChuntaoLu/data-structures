/*
 * binary_search.cpp
 *
 *  Created on: Mar 7, 2014
 *      Author: lu
 */

int binarySearch(int array[], int elt, int lo, int hi) {
	int mid;
	while (lo < hi) {
		mid = (lo + hi) >> 1;
		(elt < array[mid]) ? hi = mid : lo = mid + 1;
	}
	return --lo;
}




