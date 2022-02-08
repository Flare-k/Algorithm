#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 201
using namespace std;

vector<int> answer;
struct Node {
    int A, B, C;
};
bool visit[MAX][MAX][MAX];

void run() {
    int A, B, C;
    cin >> A >> B >> C;

    queue<Node> q;
    q.push({0, 0, C});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        int a = now.A;
        int b = now.B;
        int c = now.C;

        if (visit[a][b][c]) continue;
        visit[a][b][c] = true;

        if (a == 0) answer.push_back(c);

        // A -> B
        if (a + b > B) q.push({a + b - B, B, c});   // 넘친다면 넘치는 건 A에 두고 나머지를 모두 B에
        else q.push({0, a + b, c});                 // 안 넘치면 B에
        
        // A -> C
        if (a + c > C) q.push({a + c - C, b, C});
        else q.push({0, b, a + c});

        // B -> A
        if (b + a > A) q.push({A, b + a - A, c});
        else q.push({b + a, 0, c});

        // B -> C
        if (b + c > C) q.push({a, b + c - C, C});
        else q.push({a, 0, b + c});

        // C -> A
        if (c + a > A) q.push({A, b, c + a - A});
        else q.push({c + a, b, 0});

        // C -> B
        if (c + b > B) q.push({a, B, c + b - B});
        else q.push({a, c + b, 0});

    }

    sort(answer.begin(), answer.end());

    for (int water : answer) {
        cout << water << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    run();
   
    return 0;
}