#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    // case 1
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '6') a[i] = '5';
    }
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '6') b[i] = '5';
    }

    int sum1 = stoi(a) + stoi(b);

    // case 2
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '5') a[i] = '6';
    }
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '5') b[i] = '6';
    }

    int sum2 = stoi(a) + stoi(b);

    cout << sum1 << ' ' << sum2;

    return 0;
}