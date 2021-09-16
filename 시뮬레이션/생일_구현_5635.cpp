#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    string name;
    int day, month, year;
};

vector<Node> v;

bool cmp(Node a, Node b) {
    if (a.year < b.year) return true;
    else if (a.year == b.year) {
        if (a.month < b.month) return true;
        else if (a.month == b.month) return a.day < b.day;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string name;
    int day, month, year;

    for (int i = 0; i < n; i++) {
        cin >> name >> day >> month >> year;
        v.push_back({name,day, month, year});
    }

    sort(v.begin(), v.end(), cmp);

    cout << v.back().name << '\n';
    cout << v.front().name;

    return 0;
}