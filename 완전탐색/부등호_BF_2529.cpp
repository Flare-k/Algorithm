#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
bool used[10];
char inequal[11];
vector<string> answer;

bool checkEqual(string num) {
    int idx = 0;
    for (int i = 0; i < num.length() - 1; i++) {
        if (inequal[idx] == '<') {
            if (num[i] > num[i + 1]) return false;
        }
        else {
            if (num[i] < num[i + 1]) return false;
        }
        idx++;
    }
    return true;
}

void run(int level, string num) {
    if (level == k + 1) {
        if (checkEqual(num)) answer.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (used[i]) continue;

        used[i] = true;
        run(level + 1, num + to_string(i));
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> inequal[i];
    }

    run(0, "");

    cout << answer.back() << '\n';
    cout << answer.front() << '\n';

    return 0;
}