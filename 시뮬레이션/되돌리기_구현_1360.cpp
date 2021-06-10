#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string item;
    int time;
};

vector<Node> node;

string run(int time) {
    for (int i = node.size()- 1; i >= 0; i--) {
        if (time > node[i].time) {
            return node[i].item;
        }
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string cmd, item;
    int time;

    for (int i = 0; i < n; i++) {
        cin >> cmd >> item >> time;

        if (cmd == "type") {
            string acc;

            if (node.size()) {
                acc = node.back().item + item;
            }
            else {
                acc = item;
            }

            node.push_back({acc, time});
        }
        else {

            node.push_back({run(time - stoi(item)), time});
        }
    }

    cout << node.back().item;

    return 0;
}