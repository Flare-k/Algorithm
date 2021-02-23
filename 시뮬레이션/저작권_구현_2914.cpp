#include <iostream>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int A, I;
    cin >> A >> I;

    cout << A * (I - 1) + 1;

    return 0;
}