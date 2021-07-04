#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int country, student, score;
};

bool cmp(Node a, Node b) {
    if (a.score > b.score) return true;
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Node> arr;

    int country, student, score;
    for (int i = 0; i < n; i++) {
        cin >> country >> student >> score;
        arr.push_back({country, student, score});
    }

    sort(arr.begin(), arr.end(), cmp);

    int check[101];
    fill(check, check + 101, 0);

    int rank = 0;
    int i = 0;
    while (rank != 3) {
        Node now = arr[i];

        if (check[now.country] < 2) {
            check[now.country] += 1;
            cout << now.country << ' ' << now.student << '\n';
            rank++;
        }

        i++;
    }

    return 0;
}