#include <stdio.h>
#include <iostream>
#include <string>
#include "vector.h"

using namespace std;


void grow(Vector<char> & seq, int lo, int hi) {
	int length = seq.size();
	if (lo == -1 || hi == length || seq[lo] != seq[hi])
		seq.remove(lo + 1, hi);
	else {
		int oldLo = lo;
		int oldHi = hi;
		char letter = seq[lo];
		int counter = 0;
		while (lo > -1 && seq[lo] == letter) {lo--; counter++;}
		while (hi < length && seq[hi] == letter) {hi++; counter++;}
		if (counter < 3) seq.remove(oldLo + 1, oldHi);
		else grow(seq, lo, hi);
	}
	return;
}


void zumaInsert(Vector<char> & sequence, int pos, char letter) {
	int lo = pos - 1;
	int hi = pos;
	int counter = 0;
	int length = sequence.size();
	while (lo > -1 && sequence[lo] == letter) {lo--; counter++;}
	while (hi < length && sequence[hi] == letter) {hi++; counter++;}
	if (counter < 2) sequence.insert(pos, letter);
	else grow(sequence, lo, hi);
}


void zuma () {
	//make original sequence
	string line;
	getline(cin, line);
	int lineLength = line.size();
	char* initial = &line[0];
	Vector<char> array(initial, lineLength);

	//get insertions
	int insertNumber;
	scanf("%d", &insertNumber);
	int* positions = new int[insertNumber];
	char* letters = new char[insertNumber];
	for (int i = 0; i < insertNumber; i++) {
		scanf("%d %c", &positions[i], &letters[i]);
	}

	//zuma insert
	for(int i = 0; i < insertNumber; i++) {
		zumaInsert(array, positions[i], letters[i]);
		if (array.empty())
			printf("%c", '-');
		else
			for(int j = 0; j < array.size(); j++) printf("%c", array[j]);
		printf("\n");
	}
}


int main() {
	zuma();
	return 0;
}
