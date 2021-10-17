#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

map<string, vector<int>> m;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (string p : info) {
        string s;
        stringstream sst(p);
        vector<vector<string>> str(4, vector<string>(2, "-"));
        int idx = 0, score;

        while (sst >> s) {
            if (idx < 4) str[idx++][0] = s;
            else score = stoi(s);
        }

        // 각 조건과 '-'가 들어가는 모든 경우의 수를 map에 할당
        string lang, type, exp, food;
        for (int i = 0; i < 2; i++) {
            lang = str[0][i];
            for (int j = 0; j < 2; j++) {
                type = str[1][j];
                for (int k = 0; k < 2; k++) {
                    exp = str[2][k];
                    for (int z = 0; z < 2; z++) {
                        food = str[3][z];
                        m[lang + type + exp + food].push_back(score);
                    }
                }
            }
        }
    }

    // score 벡터 오름차순 정렬    
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }

    // query
    for (string q : query) {
        string command = "", s;
        stringstream ss(q);
        int idx = 0, score;

        while (ss >> s) {
            if (s == "and") continue;

            if (idx++ < 4) command += s;
            else score = stoi(s);
        }

        auto iter = lower_bound(m[command].begin(), m[command].end(), score);

        answer.push_back(m[command].size() - (iter - m[command].begin()));  // 찾고자하는 score 이상의 score 갯수들을 push
    }

    return answer;
}

int main() {
    vector<string> info = {"java backend senior pizza 150",
                            "python frontend senior chicken 210",
                            "python frontend senior chicken 150",
                            "cpp backend senior pizza 260",
                            "java backend junior chicken 80",
                            "python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100",
                            "python and frontend and senior and chicken 200",
                            "cpp and - and senior and pizza 250",
                            "- and backend and senior and - 150",
                            "- and - and - and chicken 100",
                            "- and - and - and - 150"};

    vector<int> sol = solution(info, query);

    for (int s : sol) {
        cout << s << ' ';
    }

    return 0;
}