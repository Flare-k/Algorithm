#include <iostream>
using namespace std;

const int LIMIT_NUMBER = 1000000007;
int tmp;

int getPower(int m, int n) {
    if (n == 0) return 1;
    else if (n % 2 == 0) {
        tmp = getPower(m, n / 2);
        return (tmp * tmp) % LIMIT_NUMBER;
    }
    else {
        tmp = getPower(m, (n - 1) / 2);
        return (tmp * tmp * m) % LIMIT_NUMBER;
    }

    return 1;
}

int main() {
    int m, n;
    cin >> m >> n;
    // 3 4

    cout << getPower(m, n);
    // 81
    
    return 0;
}