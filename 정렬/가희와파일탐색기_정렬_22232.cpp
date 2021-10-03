#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    string filename, extension;
};

int N, M;
vector<Node> v;
vector<string> filenames;
vector<string> extensions;

void split() {

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
        extensions.push_back(s);
    }


    return 0;
}