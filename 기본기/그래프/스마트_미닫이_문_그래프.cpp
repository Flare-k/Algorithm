#include <iostream>
#include <vector>
using namespace std;

const int mA[4] = {-1, 1, 0, 0};
const int mB[4] = {0, 0, -1, 1};

struct Node {
    int A, B;   // A, B의 위치
    int pass;   // 몇 번 움직였는지
    int pIdx;   // 몇 번째 손님까지 처리?
};

Node q[5000];
int head, tail;
int cnt;

vector<int> doors;
int inputSeq[12] = {0, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 3};
int minPass = 21e8;

void BFS() {
    cnt = 0;
    head = 0;
    tail = 1;

    int pIdx = 0;

    while (head != tail) {
        Node now = q[head];
        // 만약 문이 없는 곳이라면 다음 인덱스로 가고 큐에는 아무것도 넣지 않는다.

        if (inputSeq[now.pIdx] != now.A && inputSeq[now.pIdx] != now.B) {
            q[head].pIdx += 1;
            
            if (q[head].pIdx == 11) {
                //if (minPass > q[head].pass) minPass = q[head].pass;
                cout << q[head].pass;
                return;
            }

            continue;
        }

        // A 좌우, B 좌우
        for (int i = 0; i < 4; i++) {
            int newA = now.A + mA[i];
            int newB = now.B + mB[i];

            if(newA < 0 || newB < 0 || newA >= doors.size() || newB >= doors.size()) continue;
            if (newA == now.B || newB == now.A) continue;   // A가 B의 문으로 이동하려 하거나 B가 A의 문으로 이동하려 한다면 NO!


            // 만약 다음 손님이 입장하는 문에 걸린다면 인덱스 고정
            if (inputSeq[now.pIdx] == newA || inputSeq[now.pIdx] == newB) {
                q[tail++] = {newA, newB, now.pass + 1, now.pIdx};
            }
            else {
                q[tail++] = {newA, newB, now.pass + 1, now.pIdx + 1};
            }
         
        }

        head++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int door;
    for (int i = 0; i < 5; i++) {
        cin >> door;
        doors.push_back(door);
    }
    // 0 1 1 0 0
    q[0] = {1, 2, 0, 0};
    
    BFS();
    // cout << minPass;

    return 0;
}