#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;

    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        sum += pow(a, 2);
    }

    cout << sum % 10;



    return 0;
}