#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    int y, x;
};

unordered_multimap<string, Node> m;

int main() {

    string arr[5] = {"APKAB",
                    "AABAB",
                    "BACDA",
                    "ABCAB",
                    "DACDA"};

    
    string vec = "";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            vec += arr[i][j];
            vec += arr[i][j+1];
            vec += arr[i+1][j];
            vec += arr[i+1][j+1];

            m.insert({vec, {i, j}});
            vec = "";
        }
    }

    string str = "ABDA";

    auto mi = m.equal_range(str);
    for (auto i = mi.first; i != mi.second; ++i) {
        cout << i->second.y << ", " << i->second.x << '\n';
    }

    return 0;
}