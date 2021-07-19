#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> m;

struct Node {
    char name;
    int cnt;
};

vector<Node> agent = {{'B', 10}, {'T', 15}, {'S', 12}, {'G', 15}, {'O', 14}, {'D', 13}, {'Z', 16}};

int main() {

    for (Node a : agent) {
        m[a.name] = a.cnt;
    }

    char who;
    cin >> who;

    cout << m[who];

    return 0;
}