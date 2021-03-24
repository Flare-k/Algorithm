#include <iostream>
using namespace std;

int vec[100];

void insert(int v, int now) {
    if (vec[now] == 0) {
        vec[now] = v;
        return;
    }

    if (vec[now] < v) {
        insert(v, now * 2 + 1);
    }
    else {
        insert(v, now * 2);
    }
}

int find(int v, int now) {
    if (vec[now] == v) return 1;
    if (vec[now] == 0) return 0;

    int ans;

    if (vec[now] < v) {
        ans = find(v, now * 2 + 1);
    }
    else { 
        ans = find(v, now * 2);
    }

    return ans;
}

int main() {

    insert(4, 1);
    insert(2, 1);
    insert(5, 1);
    insert(9, 1);
    insert(15, 1);

    if (find(15, 1)) {
        cout << "트리에 있습니다.";
    }
    else {
        cout << "트리에 없습니다.";
    }
}