#include <iostream>

using namespace std;


// idx를 어디를 선택하느냐에 따라 max가 구해질 것이다.

int getSum(int idx, int arr[11]) {
    int ans = 0;

    for (int i = idx; i < idx + 5; i++) {
        ans += arr[i];
    }

    return ans;
}

int main() {
    int arr[11] {4, 2, 5, 1, 1, 3, 2, 4, 1, 1, 5};

    int maxNum = -1;
    int maxIdx = 0;
    for (int i = 0; i < 11 - 5 + 1; i++) {
        int sum = getSum(i, arr);
        if (maxNum < sum) {
            maxNum = sum;
            maxIdx = i;
        }
    }
    
    cout << maxIdx << '\n';

    // O(N)의 시간복잡도를 가져가기 위해 사용하는 방법이 Sliding Window이다.
    // 매번 idx ~ idx+5를 더하는게 아니라 처음 5개의 합을 구하고, 다음 순서부터는
    // 이전 순서에서 가장 앞의 요소를 빼고 맨 뒤에 와야할 값을 하나 더해준다

    int newMax = -1;
    int newIdx;
    int slideWindowSum = getSum(0, arr);
    for (int i = 0; i <= 11 - 5; i++) {
        if (newMax < slideWindowSum) {
            newMax = slideWindowSum;
            newIdx = i;
        }

        if (i == 11 - 5) break; // 마지막엔 다음껄 준비하면 안 됨

        slideWindowSum += (-arr[i] + arr[i + 5]);
    }

    cout << newIdx << '\n';

    return 0;
}