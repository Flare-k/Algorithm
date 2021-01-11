#include <iostream>
#include <vector>
using namespace std;

const int MAX = 44;
int arr[MAX + 1];

bool solution(int target) {
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++) {
            for (int k = 1; k <= MAX; k++) {
                if (arr[i] + arr[j] + arr[k] == target) return true;
            }
        }
    }
    return false;
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    init();

    for (int i = 1; i <= MAX; i++) {
        arr[i] = i * (i + 1) / 2;
    }
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cout << solution(num) << endl;
    }

    return 0;
}
