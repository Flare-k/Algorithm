#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 회의실 예약하기 | 최다 회수로 예약을 잡으려면? (A~D는 팀)
// Sol) 가능한 것 중에서 빨리 끝나는 걸 찾는다.

struct Node {
    int from;
    int to;
};

bool compare(Node& a, Node& b) {
    if (a.to < b.to) return true;
    if (a.to > b.to) return false;
    return a.from < b.from;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Node> arr;

    int from, to;
    for (int i = 0; i < 7; i++) {
        cin >> from >> to;
        arr.push_back({from ,to});
    }

    sort(arr.begin(), arr.end(), compare);
    
    int cnt = 0;
    int start = 0;

    for (auto now : arr) {
        if (now.from >= start) {
            cnt++;
            start = now.to;
        }
    }

    cout << cnt;

    return 0;
}


/*
    1시   2시   3시   4시   5시   6시   7시
A         ############    #######
B         #################
C               ###########     #######
D    ############    ##################

정답 : 4
A의 5~6시
C의 3~5시 6~7시
D의 1~3시

2 4
5 6
2 5
3 5
6 7
1 3
4 7
> 4
*/