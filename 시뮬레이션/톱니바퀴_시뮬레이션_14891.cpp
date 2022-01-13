#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;
/*  
    각 톱니바퀴 끼리 마주보는 톱니의 극이 다르면 회전
    N극: 0, S극: 1
    시계: 1, 반시계: -1 
*/
const int MAX = 5;
deque<int> dq[MAX];
bool visit[MAX];
struct Node {
    int idx, dir;
};
vector<Node> arr;

bool cmp(Node& a, Node& b) {
    if (a.idx < b.idx) return true;
    return false;
}

void clockwise(int i) {
    int num = dq[i].back();
    dq[i].pop_back();
    dq[i].push_front(num);
}

void counterclockwise(int i) {
    int num = dq[i].front();
    dq[i].pop_front();
    dq[i].push_back(num);
}

void findRotateVec(int i, int dir) {
    visit[i] = true;
    arr.push_back({i, dir});

    int left = 6, right = 2;

    if (i > 1 && i < 4) {
        if (dq[i][left] != dq[i - 1][right] && !visit[i - 1]) findRotateVec(i - 1, -dir);
        if (dq[i][right] != dq[i + 1][left] && !visit[i + 1]) findRotateVec(i + 1, -dir);
    }
    else if (i == 1) if (dq[i][right] != dq[i + 1][left] && !visit[i + 1]) findRotateVec(i + 1, -dir);
    else if (i == 4) if (dq[i][left] != dq[i - 1][right] && !visit[i - 1]) findRotateVec(i - 1, -dir);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string t;

    for (int i = 1; i <= 4; i++) {
        cin >> t;

        for (char idx : t) {
            dq[i].push_back(idx - '0');
        }
    }

    int K;
    cin >> K;

    while (K--) {
        memset(visit, false, sizeof(visit));
        arr.clear();

        int idx, dir;
        cin >> idx >> dir;

        findRotateVec(idx, dir);
        
        sort(arr.begin(), arr.end(), cmp);

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].dir == 1) clockwise(arr[i].idx);
            else counterclockwise(arr[i].idx);
        }
    }

    // 네 톱니바퀴의 점수 합
    int answer = 0;
    for (int i = 1; i <= 4; i++) {
        if (dq[i].front() == 0) continue;
        else {
            answer += pow(2, i - 1);
        }
    }

    cout << answer;

    return 0;
}