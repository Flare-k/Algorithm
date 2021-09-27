#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 20; i++) {
        card.push_back(i);
    }

    int a, b;
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        reverse(card.begin() + a - 1, card.begin() + b);
    }

    for (int i = 0; i < 20; i++) {
        cout << card[i] << ' ';
    }

    return 0;
}