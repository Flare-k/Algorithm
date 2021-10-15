#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int idx;
    int weights;
    float prob;
    int cnt;    // 자신보다 무거운 선수를 이긴 횟수
};

vector<Node> players;

bool cmp(Node a, Node b) {
    if (a.prob > b.prob) return true;
    else if (a.prob == b.prob) {
        if (a.cnt > b.cnt) return true;
        else if (a.cnt == b.cnt) {
            if (a.weights > b.weights) return true;
            else if (a.weights == b.weights) return a.idx < b.idx;
        }
    }

    return false;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    int idx = 0;

    for (string game : head2head) {
        int cnt = 0;        // W, N의 횟수
        int w = 0, l = 0;   // 승, 패
        int ow = 0;         // 나보다 무거운 사람을 이긴 경우

        for (int i = 0; i < game.size(); i++) {
            if (i == idx) continue; // 나와의 싸움 제외
            else {
                if (game[i] == 'W') {
                    w++;
                    if (weights[idx] < weights[i]) ow++;
                }
                else if (game[i] == 'L') l++;
                else continue;  // N은 노카운팅
                
                cnt++;
            }
        }

        if (cnt != 0)
            players.push_back({idx + 1, weights[idx], float(w)/cnt, ow});
        else 
            players.push_back({idx + 1, weights[idx], 0, ow});
        idx++;
    }

    sort(players.begin(), players.end(), cmp);

    for (int i = 0; i < players.size(); i++) {
        answer.push_back(players[i].idx);
    }

    return answer;
}

int main() {

    vector<int> w = {60, 70, 60};  // 복서의 몸무게
    vector<string> h = {"NNN", "NNN", "NNN"};    // N = 아직 붙어본적 없음

    vector<int> sol = solution(w, h);

    for (int s : sol) {
        cout << s << ' ';
    }

    return 0;
}