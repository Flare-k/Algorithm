#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Node {
    int x, y;
};

string king, stone;
int N;

map<string, Node> m;
Node king_dir;
Node stone_dir;

void init() {
    m["R"] = {0, 1};
    m["L"] = {0, -1};
    m["B"] = {1, 0};
    m["T"] = {-1, 0};
    m["RT"] = {-1, 1};
    m["LT"] = {-1, -1};
    m["RB"] = {1, 1};
    m["LB"] = {1, -1};

    cin >> king >> stone >> N;

    king_dir = {8 - (king[1] - '0'), king[0] - 'A'};
    stone_dir = {8 - (stone[1] - '0'), stone[0] - 'A'};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    int nx, ny;
    for (int i = 0; i < N; i++) {
        string dir;
        cin >> dir;

        int nxk = king_dir.x + m[dir].x;
        int nyk = king_dir.y + m[dir].y;
        if (nxk < 0 || nyk < 0 || nxk >= 8 || nyk >= 8) continue;
        
        king_dir = {nxk, nyk};
        
        int nxs, nys;
        bool flag = false;
        // king이 이동한 곳이 기존의 stone의 위치와 겹친다면 stone을 king이 이동한만큼 움직이기
        if (nxk == stone_dir.x && nyk == stone_dir.y) {
            nxs = stone_dir.x + m[dir].x;
            nys = stone_dir.y + m[dir].y;
            flag = true;
        }

        // stone 또한 체스판 위에서 움직여야 함
        if (flag && (nxs < 0 || nys < 0 || nxs >= 8 || nys >= 8)) continue;
        
        if (flag) stone_dir = {nxs, nys};
    }

    king = char('A' + king_dir.y) + to_string(8 - king_dir.x);
    stone = char('A' + stone_dir.y) + to_string(8 - stone_dir.x);

    cout << king << '\n';
    cout << stone << '\n';

    return 0;
}