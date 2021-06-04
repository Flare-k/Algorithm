#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int MAX = 101;

struct Node {
    int num, cnt;
};

int arr[MAX][MAX];
int tmp[MAX][MAX];
int r, c, k;

vector<Node> tmpNode;
map<int, int> m;
map<int, int>::iterator iter;

bool cmp(Node& a, Node& b) {
    if (a.cnt < b.cnt) return true;
    else if (a.cnt > b.cnt) return false;
    return a.num <= b.num;
}

void convertArr(int& row, int& col) {

    memset(tmp, 0, sizeof(tmp));

    int elem = row;
    row = col;
    col = elem;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            tmp[i][j] = arr[j][i];
        }
    }

    memcpy(arr, tmp, sizeof(arr));
}

void run(int& row, int& col) {

    int maxLen = -21e8;
    bool flag = false;
    
    if (row < col) {
        convertArr(row, col);
        flag = true;
    }
    
    for (int i = 0; i < row; i++) {
        m.clear();
        tmpNode.clear();
        
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > 0) m[arr[i][j]]++;
            arr[i][j] = 0;
        }

        for (iter = m.begin(); iter != m.end(); iter++) {
            tmpNode.push_back({iter->first, iter->second});
        }

        sort(tmpNode.begin(), tmpNode.end(), cmp);

        int c = 0;
        for (int k = 0; k < tmpNode.size(); k++) {
            arr[i][c++] = tmpNode[k].num;
            arr[i][c++] = tmpNode[k].cnt;
        }

        maxLen = max(maxLen, c);
    }
    
    col = maxLen;

    if (flag) convertArr(row, col);
}

void init() {
    cin >> r >> c >> k;

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int minTime = 0;
    int row = 3, col = 3;

    while (minTime <= 100) {
        if (arr[r - 1][c - 1] == k) break;

        run(row, col);

        minTime++;
    }

    if (minTime > 100) {
        cout << -1;
    }
    else {
        cout << minTime;
    }

    return 0;
}