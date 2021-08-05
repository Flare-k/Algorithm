#include <iostream>
using namespace std;

int E, F, C;
int sum = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> E >> F >> C;

    E += F;
    F = 0;

    while (E >= C) {
        sum += (E / C);
        E = (E / C) + (E % C);
    }

    cout << sum;
    
    return 0;
}