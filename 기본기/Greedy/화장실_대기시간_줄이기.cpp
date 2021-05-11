#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 4;
    vector<int> customers(n);

    for (int i = 0; i < 4; i++) {
        cin >> customers[i];
    }

    sort(customers.begin(), customers.end());

    int answer = 0;
    for (int i = 0; i < 4; i++) {
        answer += (customers[i]*(4 - i - 1));
    }

    cout << answer;

    return 0;
}