#include <iostream>
using namespace std;

int maxSum = -21e8;

int list[5] = {4, 7, -3, 5, 9};

void run(int level, int sum) {
    if (level == 5) {
        if (maxSum < sum) {
            maxSum = sum;
        }
        return;
    }

    run(level + 1, sum * (list[level] / 2));
    run(level + 1, sum * (list[level] * 3));
    run(level + 1, sum * (list[level] - 5));

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    run(0, 1);
    cout << maxSum;

    return 0;
}