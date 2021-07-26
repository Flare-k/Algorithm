#include <iostream>
#include <vector>
#include <string>
using namespace std;

int arr[9];
bool used[9];
vector<int> answer;
bool flag = false;

void run(int level, int sum, string str) {
    if (level == 7) {
        if (sum == 100) {
            string tmp = "";
            for (int i = 0; i < str.length(); i++) {
                if (str[i] != '+') {
                    tmp += str[i];
                }
                else {
                    answer.push_back(stoi(tmp));
                    tmp = "";
                }
            }
            flag = true;
        }
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (used[i]) continue;
        used[i] = true;
        run(level + 1, sum + arr[i], str + to_string(arr[i]) + "+");
        used[i] = false;
        if (flag) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    run(0, 0, "");

    for (int num : answer) {
        cout << num << '\n';
    }

    return 0;
}