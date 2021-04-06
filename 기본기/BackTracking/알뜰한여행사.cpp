#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<char, int>> travel[100];

bool visit[100];
char path[6];  // 중간
char res[6];   // 최종
int minSum = 21e8;
char aFrom, aTo;

void DFS(char from, int sum, int level) {
    if (level > 5) return;

    if (from == aTo) {
        if (minSum > sum) {
            minSum = sum;
            memcpy(res, path, 6);
        }
        return;
    }

    for (int i = 0; i < travel[from].size(); i++) {
        char to = travel[from][i].first;

        if (visit[to]) continue;

        visit[from] = true;
        path[level] = to;
        DFS(to, sum + travel[from][i].second, level + 1);
        path[level] = 0;
        visit[from] = false;
        
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    travel['B'].push_back({'T', 10});
    travel['G'].push_back({'T', 3});
    travel['G'].push_back({'H', 6});
    travel['G'].push_back({'K', 2});
    travel['H'].push_back({'B', 1});
    travel['K'].push_back({'B', 8});
    travel['T'].push_back({'H', 2});
    travel['T'].push_back({'B', 4});

    cin >> aFrom >> aTo;

    DFS(aFrom, 0, 0);

    if (minSum != 21e8) {
        cout << minSum << ":" << aFrom << res;
    }
    else {
        cout << "impossible";
    }

    return 0;
}