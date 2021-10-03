#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node {
    string filename, extension;
};

int N, M;
vector<Node> v;
vector<string> filenames;
unordered_map<string, bool> e;

bool cmp(Node a, Node b) {
    if (a.filename < b.filename) return true;
    else if (a.filename == b.filename) {
        if (e[a.extension] == e[b.extension]) return true;
        else if (e[a.extension] == false && e[b.extension] == true) return true;
        else if (e[a.extension] == false && e[b.extension] == false) return a.extension < b.extension;
        else return a.extension < b.extension;
    }
    return false;
}

void split() {
    for (string filename : filenames) {
        int left = 0, right = 0;
        Node now;

        while (1) {

            right = filename.find('.', left);

            if (right == -1) {
                now.extension = filename.substr(left);
                v.push_back(now);
                break;
            }

            now.filename = filename.substr(left, right - left);
            left = right + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        filenames.push_back(s);
    }

    for (int i = 0; i < M; i++) {
        cin >> s;
        e[s] = true;
    }

    split();

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].filename << '.' << v[i].extension << '\n';
    }

    return 0;
}