#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
int n;

struct Node {
    int num;
    int rank;
};

bool cmp(Node a, Node b) {
    if (a.num < b.num) return true;
    return false;
}

int main() {
    cin >> n;

    vector<Node> arr;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back({a, 0});
    }

    vector<Node> tmp(arr);
    
    sort(tmp.begin(), tmp.end(), cmp);
    map<int, int> val;

    tmp[0].rank = 0;
    val[tmp[0].num] = 0;
    for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i].num == tmp[i - 1].num) {
            tmp[i].rank = tmp[i - 1].rank;
            continue;
        }
        tmp[i].rank = tmp[i - 1].rank + 1;
        val[tmp[i].num] = tmp[i - 1].rank + 1;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << val[arr[i].num] << ' ';
    }

    return 0;
}