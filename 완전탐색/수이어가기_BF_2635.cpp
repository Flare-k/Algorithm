#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int firstNum;
    cin >> firstNum;


    vector<int> arr;
    int maxidx = -21e8;
    vector<int> answer;
    for (int i = firstNum / 2; i <= firstNum; i++) {
        arr.clear();
        arr.push_back(firstNum);
        arr.push_back(i);    // second

        int idx = 1;
        while (1) {
            int num = arr[idx - 1] - arr[idx];
            if (num >= 0) {
                arr.push_back(num);
            }
            else break;
            idx++;
        }

        if (maxidx < idx + 1) {
            maxidx = idx + 1;
            answer = arr;
        }

    }

    cout << maxidx << '\n';
    for (int num : answer) {
        cout << num << ' ';
    }

    return 0;
}