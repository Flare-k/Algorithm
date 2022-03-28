#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int idx, height;
};
struct Dir {
    int cnt, idx = 21e8;
};

vector<int> vec;
stack<Node> rst;
stack<Node> lst;
vector<Dir> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vec.resize(N);
    answer.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < N; i++) {
        int height = vec[i];

        while (!rst.empty()) {
            if (height < rst.top().height) {
                answer[i].cnt += rst.size();
                if (abs(i + 1 - answer[i].idx) > abs(i + 1 - rst.top().idx)) answer[i].idx = rst.top().idx;
                break;
            }

            rst.pop();
        }

        rst.push({i + 1, height});
    }

    for (int i = N - 1; i >= 0; i--) {
        int height = vec[i];

        while (!lst.empty()) {
            if (height < lst.top().height) {
                answer[i].cnt += lst.size();
                if (abs(i + 1 - answer[i].idx) > abs(i + 1 - lst.top().idx)) answer[i].idx = lst.top().idx;
                break;
            }
            lst.pop();
        }

        lst.push({i + 1, height});
    }
    
    for (auto a : answer) {
        if (a.cnt > 0) cout << a.cnt << ' ' << a.idx << '\n';
        else if (a.cnt == 0) cout << a.cnt << '\n';
    }

    return 0;
}