#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    int y, x;
};

int main() {

    unordered_map<string, Node> m;

    string group[3][3] = {
        "BTS", "KFC", "ATS",
        "MBC", "IU", "CTS",
        "TTL", "JU", "DTS"
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[group[i][j]] = {i, j};
        }    
    }

    string groupName;
    cin >> groupName;

    if (m.count(groupName)) cout << '{' << m[groupName].y << ", " << m[groupName].x << '}';
    else cout << "존재하지 않는 그룹입니다.";


    return 0;
}