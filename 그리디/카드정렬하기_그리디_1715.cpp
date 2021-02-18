#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    int card;
    priority_queue<int, vector<int>, greater<int>> cards;
    for (int i = 0; i < n; i++) {
        cin >> card;
        cards.push(card);
    }

    int ans = 0;
    while (cards.size() > 1) {
        int card1 = cards.top();
        cards.pop();
        int card2 = cards.top();
        cards.pop();
        
        cards.push(card1 + card2);
        ans += (card1 + card2);
    }

    cout << ans;

    return 0;
}