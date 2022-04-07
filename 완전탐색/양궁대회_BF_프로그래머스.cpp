#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 11
using namespace std;

vector<int> ryan;
vector<int> apeach;
vector<int> answer;
int maxx;

void run(int n, int level, int start) {
    if (level == n) {
        int asum = 0;
        int rsum = 0;

        for (int i = 0; i < MAX; i++) {
            if (apeach[i] == ryan[i] && apeach[i] == 0) continue;
            if (ryan[i] > apeach[i]) rsum += i;
            else asum += i;
        }

        if (maxx < rsum - asum) {
            maxx = rsum - asum;
            reverse(ryan.begin(), ryan.end());
            answer = ryan;
            reverse(ryan.begin(), ryan.end());
        }
        return;
    }

    for (int i = start; i < MAX; i++) {
        if (apeach[i] >= ryan[i]) {
            ryan[i]++;
            run(n, level + 1, i);
            ryan[i]--;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    for (int i = 10; i >= 0; i--) {
        apeach.push_back(info[i]);
    }
    ryan.resize(MAX, 0);
    run(n, 0, 0);

    if (answer.empty()) answer.push_back(-1);
    return answer;
}

void print(vector<int> sltn) {
    for (int num : sltn) {
        cout << num << ' ';
    }
    cout << '\n';
}

int main() {
    print(solution(5, {2,1,1,1,0,0,0,0,0,0,0}));   // -> 0,2,2,0,1,0,0,0,0,0,0
	return 0;
}
