#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct Node {
    int num, cnt;
};
vector<int> vect;
map<int, int> m;
vector<Node> node;

bool cmp(Node& A, Node& B) {
    if (A.cnt > B.cnt) return true;
    return false;
}

int calculateMode() {
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        node.push_back({iter->first, iter->second});
    }

    sort(node.begin(), node.end(), cmp);

    int mode;

    if (node.size() == 1) mode = node[0].num;
    else {
        if (node[0].cnt == node[1].cnt) mode = node[1].num;
        else mode = node[0].num;
    }

    return mode;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vect.resize(N);
    int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> vect[i];
        sum += vect[i];
        m[vect[i]]++;
    }

    sort(vect.begin(), vect.end());

    double avg = round(double(sum) / double(N));    // 산술 평균
    int median = vect[vect.size() / 2];             // 중간값
    int mode = calculateMode(); // 최빈값
    int diff = *max_element(vect.begin(), vect.end()) - *min_element(vect.begin(), vect.end());     // 최대 - 최소


    if (avg == -0) avg = 0;

    cout << avg << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << diff << '\n';

    return 0;
}