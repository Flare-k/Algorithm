#include <iostream>
#include <vector>
using namespace std;

int N, K, idx, cnt;
vector<int> arr;
int A, B;

void print(bool flag) {
    if (flag) {
        cout << A << ' ' << B << '\n';
    }
    else cout << -1 << '\n';
}

void input() {
    cin >> N >> K;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void bubbleSort() {
    int last = N - 1;
    for(int i = last; i >= 1 && K > 0; i--) {
        bool change = false;
        for (int j = 0; j < last && K > 0; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                K--;
                if (K == 0) {
                    A = arr[j];
                    B = arr[j + 1];
                }
                change = true;
            }
        }

        if (!change) break;
	}
}

int main() {
    
    input();
    bubbleSort();

    bool flag = K == 0 ? true : false;

    print(flag);
    
    return 0;
}
