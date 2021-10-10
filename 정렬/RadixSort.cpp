#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#define endl "\n"
#define MAX 10
using namespace std;

int Max_Value;
int arr[MAX];
bool flag[10001];
queue<int> Q[10];

void Print() {
    int cnt = 0;
    for (int i = 0; i < MAX; i++) {
        printf("%6d ", arr[i]);
        cnt++;
        if (cnt == 20) cnt = 0;
    }
    cout << endl;
}

void Radix_Sort() {
    int radix = 1;

    // 최대자릿수만큼 10씩 곱한다. 만약 Max_Value가 1234라면 Radix는 10000이 됨
    while (1) {
        if (radix >= Max_Value) break;
        radix *= 10;
    }

    for (int i = 1; i < radix; i *= 10) {
        for (int j = 0; j < MAX; j++) {
            int K;

            if (arr[j] < i) K = 0;
            else K = (arr[j] / i) % 10;

            Q[K].push(arr[j]);
        }

        int idx = 0;
        for (int j = 0; j < 10; j++) {
            while (!Q[j].empty()) {
                arr[idx] = Q[j].front();
                Q[j].pop();
                idx++;
            }
        }
    }
}

int main(void) {

    srand((unsigned)time(NULL));
    
    for (int i = 0; i < MAX;) {
        arr[i] = (rand() % 10000) + 1;

        if (flag[arr[i]] == false) {
            flag[arr[i]] = true;
            if (Max_Value < arr[i]) Max_Value = arr[i];

            i++;
        }
    }

    cout << "[ Initialize array State ] " << endl;
    Print();

    Radix_Sort();

    cout << "\n[ After Sort array State ] " << endl;
    Print();

    return 0;
}
