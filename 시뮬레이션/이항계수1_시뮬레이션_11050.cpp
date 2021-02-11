#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int numN = 1, numK = 1;

    for (int i = N; i > N - K; i--) {
        numN *= i;
    }

    for (int i = K; i > 0; i--) {
        numK *= i;
    }

    cout << numN / numK;

    return 0;
}