#include <iostream>
#include <vector>
#define MAX 6
using namespace std;

int K;
int width = 1;
int answer;
struct Node {
    int dir, length;
};

vector<Node> v;

void solution() {
    for (int i = 0; i < MAX; i++) {
        int now = v[i].length * v[(i + 1) % MAX].length;    // 가로 * 세로
        
        if (width == 1 || now > width) {
            width = now;
            answer = (width - v[(i + 3) % MAX].length * v[(i + 4) % MAX].length) * K;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;

    v.resize(MAX);

    for (int i = 0; i < MAX; i++) {
        cin >> v[i].dir >> v[i].length;
    }

    solution();

    cout << answer << '\n';

    return 0;
}