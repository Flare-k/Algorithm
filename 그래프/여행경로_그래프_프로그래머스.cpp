#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool used[10001];
vector<string> ans;

// 전부 방문했는지 체크
bool checkUsed(int len) {
    for (int i = 0; i < len; i++) {
        if (used[i] == false) return false;
    }
    return true;
}

void run(vector<vector<string>> tickets, string path, string start) {
    if (checkUsed(tickets.size()) == true)  {
        ans.push_back(path);
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (used[i]) continue;
        if (start == tickets[i][0]) {
            used[i] = true;
            run(tickets, path + tickets[i][1], tickets[i][1]);
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    // ICN에서 출발할 경우..

    run(tickets, "ICN", "ICN");

    sort(ans.begin(), ans.end());
    
    for (int i = 0; i < ans.front().length(); i += 3) {
        string tmp = ans.front().substr(i, 3);
        answer.push_back(tmp);
    }

    return answer;
}


int main() {
    vector<string> ans = solution({{"ICN", "SFO"}, 
                                    {"ICN", "ATL"}, 
                                    {"SFO", "ATL"}, 
                                    {"ATL", "ICN"}, 
                                    {"ATL","SFO"}});

    for (string passport : ans) {
        cout << passport << ' ';
    }

    return 0;
}