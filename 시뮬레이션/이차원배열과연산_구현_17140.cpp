#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define MAX 101
using namespace std;

int arr[MAX][MAX];
int tmp[MAX][MAX];
int r, c, k;
struct Node {
    int num, cnt;
};

map<int, int> m;
vector<Node> v;

bool cmp(Node& A, Node& B) {
    if (A.cnt < B.cnt) return true;
    else if (A.cnt == B.cnt) return A.num < B.num;
    return false;
}

void convertArr(int& row, int& col) {
    memset(tmp, 0, sizeof(tmp));

    swap(row, col);

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            tmp[i][j] = arr[j][i];
        }
    }

    memcpy(arr, tmp, sizeof(arr));
}

void run(int& row, int& col) {
    bool convert = false;

    if (row < col) {
        convertArr(row, col);
        convert = true;
    }

    int len = -21e8;
    
    for (int i = 1; i <= row; i++) {
        m.clear();
        v.clear();

        for (int j = 1; j <= col; j++) {
            if (arr[i][j] == 0) continue;
            m[arr[i][j]]++;
            arr[i][j] = 0;
        }

        for (auto iter = m.begin(); iter != m.end(); iter++) {
            v.push_back({iter->first, iter->second});
        }

        sort(v.begin(), v.end(), cmp);
        
        int idx = 1;
        for (int k = 0; k < v.size(); k++) {
            arr[i][idx++] = v[k].num;
            arr[i][idx++] = v[k].cnt;
        }

        len = max(len, idx);
    }

    col = len;

    if (convert) convertArr(row, col);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    
    int row = 3, col = 3, sec = 0;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> arr[i][j];
        }
    }
    
    while (sec <= 100) {
        if (arr[r][c] == k) break;
        
        run(row, col);
        sec++;
    }

    if (sec > 100) sec = -1;

    cout << sec;

    return 0;
}