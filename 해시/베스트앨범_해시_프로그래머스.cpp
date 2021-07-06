#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string genre;
    int plays;
    int idx;
};

bool cmp(Node a, Node b) {
    if (a.plays > b.plays) return true;
    return false;
}

unordered_map<string, int> m;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int len = genres.size();

    // 각 장르의 재생횟수 할당
    vector<Node> music;
    for (int i = 0; i < len; i++) {
        m[genres[i]] += plays[i];
        music.push_back({genres[i], plays[i], i});
    }

    vector<Node> total;

    for (auto i = m.begin(); i != m.end(); ++i) {
        total.push_back({i->first, i->second});
    }

    sort(total.begin(), total.end(), cmp);
    sort(music.begin(), music.end(), cmp);

    for (int i = 0; i < total.size(); i++) {
        string g = total[i].genre;
        int cnt = 0;
        for (int j = 0; j < music.size(); j++) {
            if (music[j].genre == g) {
                answer.push_back(music[j].idx);
                cnt++;
                if (cnt == 2) break;
            }
        }
    }

    return answer;
}

int main() {

    vector<int> ans = solution({"classic", "pop", "classic", "classic", "pop"}, 
                                {500, 600, 150, 800, 2500});

    for (int num : ans) {
        cout << num << ' ';
    }

    return 0;
}