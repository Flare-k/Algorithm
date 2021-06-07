#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string left, right;
    cin >> left >> right;

    long long total = 0;
    for (char str1 : left) {
        int num1 = str1 - '0';

        for (char str2 : right) {
            int num2 = str2 - '0';
            total += (num1 * num2);
        }
    }

    cout << total;

    return 0;
}