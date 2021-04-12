#include <iostream>
#include <cstring>
using namespace std;

int vect[7] = {3, 7, 4, 2, 6, 9};
int tCnt = 2;
int maxi;

void run(int level, int sum) {
	if (level == tCnt) {
		if (sum > maxi) maxi = sum;
		return;
	}

	//증식하기
	if (level > 0) {
		for (int i = 0; i < 7; i++) {
			vect[i] *= 2;
		}
	}

	//원본 백업
	int backup[7];
	memcpy(backup, vect, 7 * 4);

	for (int a = 0; a <= 2; a++) { //1번 독수리
		for (int b = 3; b <= 5; b++) { //2번 독수리
			for (int c = 1; c <= 4; c++) { //3번 독수리

				int hap = vect[a];
				vect[a] = 0;
				hap += vect[b];
				vect[b] = 0;
				hap += vect[c];
				vect[c] = 0;

				run(level + 1, sum + hap);

				//원상복구
				memcpy(vect, backup, 7 * 4);
			}
		}
	}
}

int main() {
	for (int i = 0; i < 6; i++) {
		cin >> vect[i];
	}

	cin >> tCnt;

	run(0, 0);
    
	cout << maxi;

	return 0;
}