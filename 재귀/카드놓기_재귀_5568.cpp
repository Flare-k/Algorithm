#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, K;
set<int> s;

int arr[100];
bool used[100];

void run(int level, string path) {
    if (level == K) {
        s.insert(stoi(path));
        return;
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;

        used[i] = true;
        run(level + 1, path + to_string(arr[i]));
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    run(0, "");

    cout << s.size();

    return 0;
}