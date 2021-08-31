#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int hamburger = 21e8, beverage = 21e8;

    int cost;
    for (int i = 0; i < 3; i++) {
        cin >> cost;
        hamburger = min(hamburger, cost);
    }

    for (int i = 0; i < 2; i++) {
        cin >> cost;
        beverage = min(beverage, cost);
    }

    cout << (hamburger + beverage) - 50;

    return 0;
}