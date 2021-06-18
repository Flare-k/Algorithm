#include <iostream>
#include <queue>
using namespace std;

// priority_queue가 최대힙이므로 오름차순으로 표현해주면 최소힙이 될 것

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> pq;

    int n;
    cin >> n;

    int num;
    while (n--) {
        cin >> num;

        if (num == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(-num);
        }
    }

    return 0;
}