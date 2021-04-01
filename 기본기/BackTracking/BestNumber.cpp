#include <iostream>
#include <vector>
using namespace std;

int path[5];
int used[5];
int minSum = 21e8;
int maxSum = -21e8;

int calculation(int path[]) {
    int sum = 0;

    sum = (path[0] * path[1]) - (path[2] * path[3]) + path[4];

    return sum;
}

void run(int level, vector<int> list) {
    if (level == 5) {
        int sum = calculation(path);

        if (maxSum < sum) {
            maxSum = sum;
        }
        if (minSum > sum) {
            minSum = sum;
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (used[i] == 1) continue;

        path[level] = list[i];
        used[i] = 1;
        run(level + 1, list);
        used[i] = 0;
        path[level] = 0;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> list(5);

    for (int i = 0; i < 5; i++) {
        cin >> list[i];
    }

    run(0, list);

    cout << maxSum << '\n' << minSum;
 
    return 0;
}