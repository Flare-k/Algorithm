#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define MAX 10000
using namespace std;

/*
D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
*/

struct Node {
    int num;
    string path;
};
bool visit[MAX];

void check(queue<Node>& q, int num, string path, string next) {
    if (!visit[num]) {
        visit[num] = true;
        q.push({num, path + next});
    }
}

void run(int a, int b) {
    queue<Node> q;
    q.push({a, ""});
    visit[a] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.num == b) {
            cout << now.path << '\n';
            return;
        }

        int D, S, L, R;

        // D
        D = (now.num * 2) % 10000;
        check(q, D, now.path, "D");

        // S
        S = now.num - 1 < 0 ? 9999 : now.num - 1;
        check(q, S, now.path, "S");
        
        // L
        L = (now.num % 1000) * 10 + (now.num / 1000);
        check(q, L, now.path, "L");

        // R
        R = (now.num % 10) * 1000 + (now.num / 10);
        check(q, R, now.path, "R");
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    while (N--) {
        memset(visit, false, sizeof(visit));
        int a, b;
        cin >> a >> b;
        run(a, b);
    }
    
    return 0;
}