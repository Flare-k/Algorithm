#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int player[n];

    for (int i = 0; i < n; i++) {
        cin >> player[i];
    }

    int medal[4] = {0};

    for (int i = 0; i < n; i++) {
        int idx = i;
        
        if (idx > 3) {
            medal[3] = player[idx];
            idx = 3;
        }
        else {
            medal[idx] = player[idx];
        }

        for (int j = idx; j > 0; j--) {
            if (medal[j - 1] < medal[j]) {
                swap(medal[j - 1], medal[j]);
            }
            else {
                break;
            }
        }
    }

    cout << "금" << medal[0] << '\n';
    cout << "은" << medal[1] << '\n';
    cout << "동" << medal[2] << '\n';

    return 0;
}