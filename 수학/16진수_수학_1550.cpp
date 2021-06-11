#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    int len = num.length() - 1;
    int hexa = 1;

    int sum = 0;

    while (len >= 0) {

        if (num[len] >= 'A' && num[len] <= 'Z') {
            sum += ((num[len] - 'A' + 10) * hexa);
        }
        else {
            sum += (num[len] - '0') * hexa;
        }

        hexa *= 16;
        len--;
    }

    cout << sum;

    return 0;
}