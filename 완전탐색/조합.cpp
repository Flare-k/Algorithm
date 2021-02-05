#include <iostream>

using namespace std;

/**
 * 재귀를 이용한 조합 (조합은 순서가 상관없다)
 * {1, 2, 3, 4} 4개의 숫자 중에서 순서와 상관없이 3개의 숫자를 뽑아라
 * {1, 2, 3}, {1, 3, 2} ... {2, 3, 4}
 * 
 * 시작점을 결정한 이후, 그 전의 요소는 보지않는 것이 중요
 */

const int MAX = 50;
bool select[MAX]; //이미 선택한 숫자라면 선택하지 않고, 선택하지 않은 숫자라면 선택할 수 있음을 표시해주는 배열
int arr[MAX];


void printArr() {
    for (int i = 0; i < MAX; i++) {
        if (select[i] == true) {
            cout << arr[i] << " ";
        }
    }
    cout << '\n';
}

void combination(int n, int pick, int idx, int cnt) {
    if (cnt == pick) {
        printArr();
        return;
    }

    for (int i = idx; i < n; i++) {
        if (select[i] == true) continue;
        
        select[i] = true;
        combination(n, pick, i, cnt + 1);
        select[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, pick;
    cout << "최대값: ";
    cin >> n;
    cout << "몇 개의 수를 뽑을 것인가? ";
    cin >> pick;

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    combination(n, pick, 0, 0);

    return 0;
}