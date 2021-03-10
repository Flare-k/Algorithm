#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int road[9] = {1, 2, 3, 3, 5, 1, 0, 1, 3};

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += road[i];
    }

    int minSum = 987654321;
    for (int i = 0; i <= 9 - n; i++) {
        if (sum < minSum) minSum = sum;

        if (i == 9 - n) break;

        sum += road[i + n];
        sum -= road[i];
    }

    cout << minSum;

    return 0;
}