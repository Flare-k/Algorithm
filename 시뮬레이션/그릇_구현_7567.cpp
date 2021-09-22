#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 10;

    string plates;
    cin >> plates;

    for (int i = 1; i < plates.length(); i++) {
        if (plates[i - 1] == plates[i]) sum += 5;
        else sum += 10;
    }

    cout << sum;

    return 0;
}