#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

/* 
Convex Hull이란 점들로 구성된 Set을 모두 포함하는 '외각 점들의 집합'이다.
노드가 좌회전하는지 우회전하는지는 Counter Clock Wise로 알 수 있다. CCW는 벡터 값으로 표현된 노드들에 대해 외적을 수행한 값이다.
1) CCW(A, B, C) > 0 : 좌회전 (Left Turn)
2) CCW(A, B, C) < 0 : 우회전 (Right Turn)
3) CCW(A, B, C) = 0 : 3개의 노드가 일직선상에 있음

대표예제 : https://www.acmicpc.net/problem/1708
*/

struct Node {
    int x, y;
};

int N;
vector<Node> vec;

// 벡터의 방향이 중요하므로 양/음수에 대한 스칼라 값을 리턴
ll calculate(Node& A, Node& B) {
    return (ll)A.x * B.y - (ll)A.y * B.x;
}

int CCW(Node& A, Node& B, Node& C) {
    Node X = {B.x - A.x, B.y - A.y};
    Node Y = {C.x - A.x, C.y - A.y};

    ll value = calculate(X, Y); // 두 벡터에 대한 외적

    if (value > 0) return 1;
    if (value < 0) return -1;

    return 0;
}

// 아래쪽 기준으로 정렬시킨다.
bool cmp(Node& A, Node& B) {
    int value = CCW(vec[0], A, B);
    if (value > 0) return true;     // left
    if (value < 0) return false;    // right
    if (A.x != B.x) return A.x < B.x;
    return A.y < B.y;
}

vector<Node> GrahamScan() {
    // 스택을 이용해 좌회전 여부를 검사한다.
    vector<Node> stk;

    for (int i = 0; i < vec.size(); i++) {
        while (stk.size() >= 2) {
            Node first = stk[stk.size() - 2];
            Node second = stk.back();
            Node next = vec[i];
            
            int val = CCW(first, second, next);
            
            if (val > 0) break; // left

            stk.pop_back();
        }

        stk.push_back(vec[i]);
    }

    return stk;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int idx = 0;
    
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a  >> b;
        vec.push_back({a, b});

        if (vec[idx].x > vec[i].x || vec[idx].x == vec[i].x && vec[idx].y > vec[i].y) idx = i;
    }

    // idx를 통해 가장 아래쪽에 위치한 점을 찾는다.
    // 이 지점은 무조건 Convec Hull에 포함되므로 vec[0]에 포함시킨다.
    swap(vec[idx], vec[0]);

    // 기준점을 대상으로 모든 노드를 반시계 방향으로 정렬한다.
    sort(vec.begin() + 1, vec.end(), cmp);

    // 이미 CCW로 정렬시켰기 때문에 O(n)의 시간복잡도를 갖게 된다.
    vector<Node> con = GrahamScan();

    cout << con.size() << '\n';

    return 0;
}