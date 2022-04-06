#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>
using namespace std;

int get_minimum_trashes(int **waste, int N, int K) {
	int answer = K * K;
    int r = 0, c = 0;

    while (1) {
        int sum = 0;
        for (int i = r; i < r + K; i++) {
            for (int j = c; j < c + K; j++) {
                sum += waste[i][j];
            }
        }

        answer = min(answer, sum);
        c++;

        if (c + K > N) {
            r++;
            c = 0;
            if (r + K > N) break;
        }
    }

	return answer;
}

void test_case(int caseIndex) {
	int N, K;
	scanf("%d %d", &N, &K);

	int **wastes = new int *[N];
	for (int r = 0; r < N; r += 1) {
		wastes[r] = new int[N];
		for (int c = 0; c < N; c += 1) {
			scanf("%d", &wastes[r][c]);
		}
	}

	int answer = get_minimum_trashes(wastes, N, K);
	printf("%d\n", answer);

	for (int r = 0; r < N; r += 1) {
		delete[] wastes[r];
	}
	delete[] wastes;
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 0; caseIndex < caseSize; caseIndex += 1) {
		test_case(caseIndex);
	}
	return 0;
}