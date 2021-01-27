#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 거스름돈.. 2원과 5원의 조합으로 동전의 개수를 최소한으로 줘야함
    
    int n;
    cin >> n;

    int charge = 0;

    if (n == 1 || n == 3) {
        cout << -1;
    }
    else if (n % 5 == 0) {
        charge += (n / 5);
        cout << charge;
    }
    else {
       while (n != 0) {
           n -= 2;
           charge++;
           if (n % 5 == 0) {
               charge += (n / 5);
               n %= 5;
           }
       }
       cout << charge;
    }

    return 0;
}