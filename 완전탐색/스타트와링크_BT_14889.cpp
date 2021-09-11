#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 20 + 1;
int arr[MAX][MAX];
bool team[MAX];
int n;
int ans = 999999999;

void go(int idx, int cnt) {
    vector<int> star;
    vector<int> link;

    int starScore = 0;
    int linkScore = 0;

    if (n / 2 == cnt) {
        for (int i = 0; i < n; i++) {
            if (team[i])
                star.push_back(i);  // 해당 팀원의 인덱스를 담는 과정
            else
                link.push_back(i);
        }
        for (int i = 0; i < (n / 2); i++) {
            for (int j = 0; j < (n / 2); j++) {
                starScore += arr[star[i]][star[j]];
                linkScore += arr[link[i]][link[j]];
            }
        }

        ans = min(ans, abs(starScore - linkScore));
        
        return;
    }

    for (int i = idx; i < n; i++) {
        if (team[i])
            continue;
        else {
            team[i] = true;
            go(i, cnt + 1);
            team[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    go(0, 0);

    cout << ans << endl;
    return 0;
}

/*
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0
> 0

6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0
>2

8
0 5 4 5 4 5 4 5
4 0 5 1 2 3 4 5
9 8 0 1 2 3 1 2
9 9 9 0 9 9 9 9
1 1 1 1 0 1 1 1
8 7 6 5 4 0 3 2
9 1 9 1 9 1 0 9
6 5 4 3 2 1 9 0
>1
*/