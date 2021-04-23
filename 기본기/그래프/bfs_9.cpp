#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

// ABTKG -> TBGAK 각각 두 문자씩 swap을 해서 target으로 되기 위해 최소 몇번의 swap을 해야하는가

string start = "ABTKG";
string target = "TBGAK";

struct Node {
    int level;
    string seq;
};

queue<Node> q;

int head;
int tail = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    q.push({0, start});
    int len = start.length();

    while (!q.empty()) {
        Node now = q.front();

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                Node next = now;
                swap(next.seq[i], next.seq[j]);
                q.push({next.level + 1, next.seq});

                if (next.seq == target) {
                    cout << next.level << "회";
                    return 0;
                }
            }
        }

        q.pop();
    }

    return 0;
}