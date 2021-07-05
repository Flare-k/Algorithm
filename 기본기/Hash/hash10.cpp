#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node {
    int i, j;
};

int main() {
    
    string s = "ABCABTTKRACKBC";

    unordered_map<string, Node> m;

    for (int i = 0; i < s.length() - 4; i++) {
        string tmp = s.substr(i, 5);
        m[tmp] = {i, i + 4};
    }

    // 다섯글자 입력
    string str;
    cin >> str;

    cout << m[str].i << " ~ " << m[str].j << '\n';
    
    return 0;
}