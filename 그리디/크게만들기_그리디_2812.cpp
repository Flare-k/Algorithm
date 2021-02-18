#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    deque<char> dq;

    for (int i = 0; i < s.length(); i++) {
        while (K && !dq.empty() && dq.back() < s[i]) {
            dq.pop_back();
            K--;
        }
        dq.push_back(s[i]);
    }

    for (int i = 0; i < dq.size() - K; i++) {
        cout << dq[i];
    }
    

    return 0;
}