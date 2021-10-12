#include <iostream>
using namespace std;

int N;
int t[51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    int s = t[0];
    int e = t[N-1];

    int left = 1, right = 1;
    
    for (int i = 1; i < N; i++) {
        if (s < t[i]) {
            s = t[i];
            left++;
        }
    }
    
    for (int i = N-1; i >= 0; i--) {
        if (e < t[i]) {
            e = t[i];
            right++;
        }
    }

    cout << left << '\n' << right;

    return 0;
}