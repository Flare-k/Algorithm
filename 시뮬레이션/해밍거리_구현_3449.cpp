#include <iostream>
#include <string>
using namespace std;

int testCase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testCase;

    while (testCase--) {
        string a, b;
        int cnt = 0;
        cin >> a >> b;

        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) cnt++;
        }

        cout << "Hamming distance is " << cnt << ".\n";
    }
  
    return 0;
}