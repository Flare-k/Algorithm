#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

int cnt[11];
bool used[27];

unordered_map<string, int> map;
unordered_map<int, vector<string>> maxCourseOrder;

void run(int level, int target, string& order, string tmp, int start) {
    if (target == level) {
        sort(tmp.begin(), tmp.end());   // 사전순으로 정렬

        map[tmp]++;

        int len = tmp.length();

        if (cnt[len] < map[tmp]) {
            cnt[len] = map[tmp];
            maxCourseOrder[len].clear();    // 만약 최대 케이스가 바뀐다면 새로 벡터 갱신
            maxCourseOrder[len].push_back(tmp);
        }
        else if (cnt[len] == map[tmp]) {
            maxCourseOrder[len].push_back(tmp);
        }

        return;
    }

    for (int i = start; i < order.length(); i++) {
        if (used[order[i] - 'A']) continue;
        used[order[i] - 'A'] = true;
        run(level + 1, target, order, tmp + order[i], i + 1);
        used[order[i] - 'A'] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string order : orders) {
        for (int i = 2; i <= order.length(); i++) { // 각 order의 길이마다 백트래킹
            memset(used, false, sizeof(used));
            run(0, i, order, "", 0);
        }
    }

    for (int num : course) {
        
        for (int i = 0; i < maxCourseOrder[num].size(); i++) {
            string str = maxCourseOrder[num][i];
            if (map[str] > 1) answer.push_back(str);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<string> ans = solution({"XYZ", "XWY", "WXA"}, {2, 3, 4});

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}