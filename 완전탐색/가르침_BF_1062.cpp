#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, K;
vector<string> vec;
bool visit[26];
int answer;

void run(int level, int start) {
    if (level == K) {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            bool flag = true;

            for (int j = 0; j < vec[i].length(); j++) {
                if (!visit[vec[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }

            if (flag) cnt++;
        }

        answer = max(answer, cnt);
        
        return;
    }

    for (int i = start ; i < 26; i++) {
        if (visit[i]) continue;

        visit[i] = true;
        run(level + 1, i + 1);
        visit[i] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }
    else if (K == 26) {
        cout << N << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        str = str.substr(4);
        str = str.substr(0, str.length() - 4);

        vec.push_back(str);
    }

    visit['a' - 'a'] = true;
    visit['c' - 'a'] = true;
    visit['n' - 'a'] = true;
    visit['i' - 'a'] = true;
    visit['t' - 'a'] = true;

    K -= 5;

    run(0, 0);

    cout << answer << '\n';

    return 0;
}