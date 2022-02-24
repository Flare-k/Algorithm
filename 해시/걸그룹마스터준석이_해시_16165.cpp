#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, vector<string>> teams;
map<string, string> singer;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        vector<string> v;
        string team;
        int num;

        cin >> team >> num;
        
        while (num--) {
            string name;
            cin >> name;

            singer[name] = team;
            v.push_back(name);
        }

        sort(v.begin(), v.end());

        teams[team] = v;
    }

    // 문제
    for (int i = 0; i < M; i++) {
        string name;
        int num;
        
        cin >> name >> num;

        // 팀 이름 출력
        if (num == 0) {
            for (string s : teams[name]) {
                cout << s << '\n';
            }
        }
        // 해당 멤버가 속한 팀의 이름 출력
        else {
            cout << singer[name] << '\n';
        }
    }
   
    return 0;
}