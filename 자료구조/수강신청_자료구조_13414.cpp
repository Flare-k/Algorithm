#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K, L;

    cin >> K >> L;

    map<string, int> m;
    queue<string> q;

    while (L--) {
        string id;
        cin >> id;

        q.push(id);
        m[id]++;        
    }

    int iter = 0;

    while (!q.empty() && iter != K) {
        string id = q.front();

        if (m[id] - 1 == 0) {
            cout << q.front() << '\n';
            iter++;
        }
        else m[id]--;

        q.pop();
    }

    return 0;
}