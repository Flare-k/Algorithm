#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int N, M, A, B;
// West North East South
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
int arr[MAX][MAX];
struct Node {
    int x, y, dir;
};
enum {
    WEST, NORTH, EAST, SOUTH
};
vector<Node> robot;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;  // B행 A열
    cin >> N >> M;

    // 각 로봇의 초기 위치
    for (int num = 1; num <= N; num++) {
        int x, y;
        char d;

        cin >> y >> x >> d; // x행 y열

        if (d == 'N') robot.push_back({B - x, y - 1, NORTH});
        else if (d == 'W') robot.push_back({B - x, y - 1, WEST});
        else if (d == 'E') robot.push_back({B - x, y - 1, EAST});
        else if (d == 'S') robot.push_back({B - x, y - 1, SOUTH});
        
        arr[B - x][y - 1] = num;
    }

    // 명령
    for (int i = 0; i < M; i++) {
        int num, iter;
        char type;  // L R F

        cin >> num >> type >> iter;   // 로봇 번호, 명령의 종류, 반복 횟수

        while (iter--) {
            Node now = robot[num - 1];

            int x = now.x, y = now.y;
            int d = now.dir;

            if (type == 'F') {
                // 전진
                int nx = x + dx[d];
                int ny = y + dy[d];

                // 벽 or 나가는 경우
                if (nx < 0 || nx >= B || ny < 0 || ny >= A) {
                    cout << "Robot " << num << " crashes into the wall" << '\n';
                    return 0;
                }
                // 다른 로봇과 부딪히는 경우
                else if (arr[nx][ny]) {
                    cout << "Robot " << num << " crashes into robot " << arr[nx][ny] <<'\n';
                    return 0;
                }

                swap(arr[nx][ny], arr[x][y]);

                robot[num - 1].x = nx;
                robot[num - 1].y = ny;
            }
            else if (type == 'L') {
                robot[num - 1].dir = d - 1 < 0 ? 3 : d - 1;
            }
            else if (type == 'R') {
                robot[num - 1].dir = d + 1 == 4 ? 0 : d + 1;
            }
        }

    }

    cout << "OK" << '\n';

    return 0;
}