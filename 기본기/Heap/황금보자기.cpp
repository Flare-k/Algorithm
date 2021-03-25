#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct Node {
    int stone;
    bool check;
};

bool operator<(Node t1, Node t2) {
    if (t1.stone > t2.stone) return true;
    if (t1.stone < t2.stone) return false;
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<Node> pq;

    int stone;
    for (int i = 0; i < n; i++) {
        cin >> stone;
        pq.push({stone, false});
    }

    bool visit[100];
    int cnt = 0;

    while (1) {
        int count = 2;

        while (count-- && !pq.top().check) {
            if (count == 0){
                int top = pq.top().stone * 2;
                pq.pop();
                pq.push({top, true});
            }
            else {
                pq.pop();
            }
            
            cnt += 1;
        }
        
        if (count == 1 && pq.top().check) break;
        
    }
    

    cout << cnt;

    return 0;
}