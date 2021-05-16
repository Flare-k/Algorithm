#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[50];
int acc[50];
int maxScore = -21e8;

void write(int index, int value) {
	if (index >= 12 && maxScore < value) maxScore = value;
	if (acc[index] < value) acc[index] = value;
}

int main() {
	for (int i = 0; i < 12; i++) {
		cin >> map[i];
		acc[i] = -99999;
	}

	int a, b, c;
	acc[0] = map[0];

	for (int i = 0; i < 12; i++) {
		write(i + 2, acc[i] + map[i + 2]);
		write(i + 3, acc[i] + map[i + 3]);
		write(i * 2, acc[i] + map[i * 2]);
	}

	cout << maxScore;

	return 0;
}

// 0 2 4 -5 -7 6 20 7 -10 -8 4 -1 > 21
// 0 1 1 1 1 1 2 3 -5 -10 -20 30 > 29
/*
0 1 2  3  4 5  6  7  8  9 10 11
0 2 4 -5 -7 6  20 7 -10 -8 4 -1
0 2 6 -3 -1 12 19 19 9  11 23 10



0 1 2 3 4 5 6 7  8  9  10 11
0 1 1 1 1 1 2 3 -5 -10 -20 30
0 1 2 2 3 3 5 6 0  -4  -14 30
*/