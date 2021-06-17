#include <iostream>
#define ll long long
using namespace std;

int vect[1000001] = {0, };

int main() {

    int n;
    cin >> n;

    vect[1] = 1;
    vect[2] = 2;

    for (int i = 3; i < 1000001; i++) {
        vect[i] = (vect[i - 1] + vect[i - 2]) % 15746;
    }

    cout << vect[n] % 15746;
}