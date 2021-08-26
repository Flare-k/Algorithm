#include <iostream>
using namespace std;

int ranks[11];
int start, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> start;

        for (int j = 0; j < N; j++) {
            if (start == 0 && ranks[j] == 0) {
                ranks[j] = i + 1;
                break;
            }
            else if (ranks[j] == 0) {
                start--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ranks[i] << ' ';
    }

    return 0;
}