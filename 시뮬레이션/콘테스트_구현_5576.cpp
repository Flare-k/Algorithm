#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> W;
vector<int> K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;

    for (int i = 0; i < 20; i++) {
        cin >> num;

        if (i < 10) {
            W.push_back(num);
        }
        else {
            K.push_back(num);
        }
    }

    sort(W.begin(), W.end(), greater<int>());
    sort(K.begin(), K.end(), greater<int>());

    int sumW = 0, sumK = 0;

    for (int i = 0; i < 3; i++) {
        sumW += W[i];
        sumK += K[i];
    }

    cout << sumW << ' ' << sumK;

    return 0;
}