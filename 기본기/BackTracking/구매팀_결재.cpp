#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> list = {15, 20, 44, 22, 55, 16, 45};
int used[100];

int maxSum = -21e8;
// a = 97

void run(int level, string inputList, int n, int sum) {
    if (level == inputList.length() - n) {
        if (sum % 10 == 0 && maxSum < sum) {    // 10의 배수인지 확인
            maxSum = sum;
        }
        return;
    }

    for (int i = 0; i < inputList.length(); i++) {
        if (used[i] == 1) continue;

        used[i] = 1;
        run(level + 1, inputList, n, sum + list[inputList[i] - 97]);    // a의 ASCII code 값은 97
        used[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inputList;
    int n;

    cin >> inputList >> n;

    run(0, inputList, n, 0);

    cout << maxSum;
  
    return 0;
}