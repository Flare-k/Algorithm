#include <iostream>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int res;
    cin >> res;

    int sum = 0;
    int price;
    for (int i = 0; i < 9; i++) {
        cin >> price;
        sum += price;
    }

    cout << res - sum;
    return 0;

}