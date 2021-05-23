#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {

    int n;
    cin >> n;

    int first;
    cin >> first;

    int ring;
    for (int i = 1; i < n; i++) {
        cin >> ring;
        int num = gcd(first, ring);

        cout << first / num << "/" << ring / num << '\n';
    }

    return 0;
}