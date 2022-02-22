#include <iostream>
#define MAX 100001
#define ll long long
using namespace std;

int N;
int arr[MAX];
bool visit[MAX];

ll sum(int n) {
    return (ll)n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int s = 0, e = 0;
    ll answer = 0;

    while (s < N && e < N) {
        if (visit[arr[e]]) {
            answer += (e - s);
            visit[arr[s]] = false;
            s++;
        }
        else {
            visit[arr[e]] = true;
            e++;
        }
    }

    // 모든 숫자가 한번만 등장하는 구간
    answer += sum(e - s);

    cout << answer;

    return 0;
}