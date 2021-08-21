#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Node {
    int value;
    long long gop;
};

map<string, Node> m;

void init() {
    m["black"] = {0, 1};
    m["brown"] = {1, 10};
    m["red"] = {2, 100};
    m["orange"] = {3, 1000};
    m["yellow"] = {4, 10000};
    m["green"] = {5, 100000};
    m["blue"] = {6, 1000000};
    m["violet"] = {7, 10000000};
    m["grey"] = {8, 100000000};
    m["white"] = {9, 1000000000};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    string color;
    long long num = 0;
    long long idx = 10;
    for (int i = 0 ; i < 2; i++) {
        cin >> color;
        num += (m[color].value * idx);
        idx /= 10;
    }

    cin >> color;

    num = num * m[color].gop;

    cout << num;

    return 0;
}