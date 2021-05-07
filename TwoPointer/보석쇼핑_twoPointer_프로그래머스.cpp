#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int> m;
    set<string> tmp(gems.begin(), gems.end());

    int setSize = tmp.size();
    int dist, start = 0, end;
    int idx = 0;

    for (string gem : gems) {
        m[gem]++;

        if (m.size() >= setSize) {
            end = idx;
            break;
        }

        idx++;
    }

    answer[0] = start + 1;
    answer[1] = end + 1;
    dist = end - start;

    while (end < gems.size()) {
        string gem = gems[start];
        m[gem]--;
        start++;

        if (m[gem] == 0) {  // 포함되지 못하는 경우가 
            end++;
            while (end < gems.size()) {
                m[gems[end]]++;
                if (gems[end] == gem) break;    // 모든 경우를 포함한다면 break
                end++;
            }
        }
        
        if (end - start < dist) {
            dist = end - start;
            answer[0] = start + 1;
            answer[1] = end + 1;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> gems = solution({"A", "B", "B", "C", "D", "B"});

    for (int i = 0; i < 2; i++) {
        cout << gems[i] << ' ';
    }

    return 0;
}

/*
["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]	[3, 7]
["AA", "AB", "AC", "AA", "AC"]	[1, 3]
["XYZ", "XYZ", "XYZ"]	[1, 1]
["ZZZ", "YYY", "NNNN", "YYY", "BBB"]	[1, 5]
["A", "A", "B"]     [2, 3]
["A", "B", "B", "C", "D", "B"]      [1, 5]
*/