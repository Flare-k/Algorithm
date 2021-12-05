#include <iostream>
using namespace std;

int N;

int score[] = {100, 100, 200, 200, 300, 300, 400, 400, 500};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    bool flag = false;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> num;
        if (num > score[i]) {
            cout << "hacker";
            flag = true;
            break;
        }
        sum += num;
    }

    if (sum >= 100 && !flag) {
        cout << "draw";
    }
    else if (sum < 100 && !flag){
        cout << "none";
    }

    return 0;
}