#include <iostream>
using namespace std;

struct Node {
    int first, second;
};

// 조건, 첫번째 숫자 내림차순, 두번째 숫자 오름차순
bool compare(Node v1, Node v2) {
    if (v1.first > v2.first) 
        return true;
    if (v1.first < v2.first)
        return false;

    return v1.second < v2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node vect[7] = {{4, 2}, {5, 3}, {1, 6}, {2, 3}, {2, 9}, {3, 7}, {5, 2}};

    sort(vect, vect + 7, compare);

    for (int i = 0; i < 7; i++) {
        cout << '(' << vect[i].first << ", " << vect[i].second << ')' << '\n';
    }

    return 0;
}