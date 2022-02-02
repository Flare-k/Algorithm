#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> friends[MAX];

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        friends[A].push_back(B);
        friends[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        cout << friends[i].size() << '\n';
    }

    return 0;
}