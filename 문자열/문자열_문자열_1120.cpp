#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int min = 50;
    for (int i = 0; i <= b.length() - a.length(); i++) {
        int cnt= 0;

        for (int j = 0; j < a.length(); j++) {
            if (a[j] != b[i + j]) {
                cnt++;
            }
        }

        min = min > cnt ? cnt : min;
    }

    cout << min;

    return 0;
}