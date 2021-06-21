#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 10000 + 1;
int arr[MAX];
bool visit[MAX];

void erathosthenes() {
    arr[0] = 0;
    arr[1] = 0;
    
    for (int i = 2; i <= MAX; i++) {
        arr[i] = i;
    }

    for (int i = 2; i <= MAX; i++) {
        if (arr[i] == 0) continue;
        for (int j = i + i; j <= MAX; j += i) {
            arr[j] = 0;
        }
    }
}

struct Node {
    int num, cnt;
};

string bfs(int num, int target) {
    queue<Node> q;
    memset(visit, false, sizeof(visit));

    q.push({num, 0});
    visit[num] = true;


    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.num == target) {
            return to_string(now.cnt);
        }

        int idx = 0;
        
        string a = to_string(now.num);

        while (idx != 4) {
            
            int tmp = a[idx % 4] - '0';
            string nextNum = a;

            for (int i = 0; i < 10; i++) {
                nextNum[idx % 4] = i + '0';

                int tmpNum = stoi(nextNum);
                
                if (visit[tmpNum] == true) continue;
                if (now.num == tmpNum) continue;
                if (tmpNum < 1000) continue;

                if (arr[tmpNum] == tmpNum) {
                    q.push({tmpNum, now.cnt + 1});
                    visit[tmpNum] = true;
                }
            }

            idx++;
        }

    }

    return "Impossible";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(arr, 0, sizeof(arr));
    erathosthenes();

    int n;
    cin >> n;

    int num, t;
    while (n--) {
        cin >> num >> t;
        cout << bfs(num, t) << '\n';
    }

    return 0;
}