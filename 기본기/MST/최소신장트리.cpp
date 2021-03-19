#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    최소신장트리 MST
    = 스패닝 트리

    각 노드를 모두 연결하는데 필요한 최소 비용은?
    -> 역시 Union Find로 접근가능하다.
    -> 크루스컬 알고리즘

    각 노드와 가중치를 모두 오름차순으로 정렬한다. 즉, 가장 저렴한 비용부터 확인한다.
    이미 그룹이면 그룹을 맺지 않는다.
*/

struct Node {
    char c1;
    char c2;
    int value;
};
/*
A B 5
A C 3
A D 2
C D 4
B C 7
A E 6
C E 2
B E 8
*/
int vect[100];

vector<Node> list = {
    {'A', 'B', 5},
    {'A', 'C', 3},
    {'A', 'D', 2},
    {'C', 'D', 4},
    {'B', 'C', 7},
    {'A', 'E', 6},
    {'C', 'E', 2},
    {'B', 'E', 8}
};

bool cmp(Node a, Node b) {
    if (a.value < b.value) return true;
    return false;
}

char getBoss(char ch) {
    if (vect[ch] == 0) return ch;

    int res = getBoss(vect[ch]);
    vect[ch] = res;
    return res;
}

void setGroup(char c1, char c2) {
    char g1 = getBoss(c1);
    char g2 = getBoss(c2);

    if (g1 == g2) return;
    vect[g2] = g1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sort(list.begin(), list.end(), cmp);

    int price = 0;
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (getBoss(list[i].c1) != getBoss(list[i].c2)) {
            cnt++;
            price += list[i].value;
            setGroup(list[i].c1, list[i].c2);

            if (cnt == 4) break; // 노드가 총 5개이므로 모두 그룹이 맺어질려면 네 번이면 된다.
        }
    }

    cout << price;

    return 0;
}