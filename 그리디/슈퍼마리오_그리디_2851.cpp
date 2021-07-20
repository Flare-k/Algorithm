#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int superMario = 0;

    int mushroom[10];
    for (int i = 0; i < 10; i++) {
        cin >> mushroom[i];
    }

    for (int i = 1; i < 10; i++) {
        mushroom[i] += mushroom[i - 1];
    }

    int a, b;
    for (int i = 0; i < 9; i++) {
        if (mushroom[i] <= 100 && 100 <= mushroom[i + 1]) {
            a = mushroom[i];
            b = mushroom[i + 1];
            break;
        }
    }

    if (100 - a < b - 100) cout << a;
    else cout << b;

    return 0;
}