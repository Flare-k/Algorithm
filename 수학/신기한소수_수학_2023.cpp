#include <iostream>
#include <string>
using namespace std;

char arr[10];

void run(int level, int n) {
    if (level == n) {
        cout << arr << '\n';
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (level == 0 && i == 1) continue;

        arr[level] = i + '0';
        string s = arr;
        long long sosu = stoi(s);

        int cnt = 0;

        for (int j = 2; j*j <= sosu; j++) {
            if (sosu % j == 0) {
                cnt++;
                break;
            }
        }
        
        if (cnt == 0) run(level + 1, n);

        arr[level] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    run(0, n);

    return 0;
}