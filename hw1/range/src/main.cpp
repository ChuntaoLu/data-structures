//============================================================================
// Name        : hw1.cpp
// Author      : lu
// Version     : 0
// Copyright   : Your copyright notice
// Description : Range search in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "sort.h"
#include "binary_search.h"

using namespace std;


int rangeSearch(int array[], int arrayLength, int a, int b) {
	int left = binarySearch(array, a, 0, arrayLength);
	int right = binarySearch(array, b, (left < 0) ? 0 : left, arrayLength);
	if (left >= 0 && a == array[left]) {left--;}
	return right - left;
}


void range() {
	int arrayLength, queryNumber;
	cin >> arrayLength >> queryNumber;
    int* array = new int[arrayLength];
	int* output = new int[queryNumber];
	int left, right;
    for (int i = 0; i < arrayLength; i++) scanf("%d", &array[i]);
    mergeSort(array, 0, arrayLength);
    for (int i = 0; i < queryNumber; i++) {
        scanf("%d", &left);
        scanf("%d", &right);
        output[i] = rangeSearch(array, arrayLength, left, right);
    }
    for (int i = 0; i < queryNumber; i++) {printf("%d\n", output[i]);}
}



int main() {
	range();
	return 0;
}
