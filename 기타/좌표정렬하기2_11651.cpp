#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int a, b;
};

bool compare(Node& n1, Node& n2) {
    if (n1.b == n2.b) return n1.a < n2.a;
    return n1.b < n2.b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Node> pnt;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pnt.push_back({a, b});
    }
    sort(pnt.begin(), pnt.end(), compare);

    for (int i = 0; i < n; i++) {
        cout << pnt[i].a << " " << pnt[i].b << '\n';
    }
    
    return 0;
}
