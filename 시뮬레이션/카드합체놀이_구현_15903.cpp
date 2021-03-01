#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();

    int n, m;  // 카드의 수, 카드합체 수

    cin >> n >> m;

    vector<long long> card(n);

    for (int i = 0 ; i < n; i++) {
        cin >> card[i];
    }

    while (m--) {
        sort(card.begin(), card.end());

        long long tmp = 0;

        tmp += (card[0] + card[1]);
        card[0] = tmp;
        card[1] = tmp;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += card[i];
    }

    cout << sum;

    return 0;
}