#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, country;

struct Node {
    int num, gold, silver, bronze;
};

bool cmp(Node a, Node b) {
    if (a.gold > b.gold) return true;
    else if (a.gold == b.gold) {
        if (a.silver > b.silver) return true;
        if (a.silver == b.silver) {
            if (a.bronze > b.bronze) return true;
        }
    }
    return false;
}

vector<Node> olympic;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> country;

    for (int i = 0; i < N; i++) {
        int c, g, s, b;
        cin >> c >> g >> s >> b;
        olympic.push_back({c, g, s, b});
    }

    sort(olympic.begin(), olympic.end(), cmp);

    int score = 0;
    int term = 0;

    if (olympic[0].num == country) {
        cout << 1;
    }
    else {
        for (int i = 1; i < N; i++) {
            term++;

            if (olympic[i-1].gold != olympic[i].gold || olympic[i-1].silver != olympic[i].silver || olympic[i-1].bronze != olympic[i].bronze) {
                score = term;
            }

            if (olympic[i].num == country) {
                cout << score + 1;
                break;
            }

        }
    }

    return 0;
}