#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

const int MAX = 100;
vector<int> arr[MAX];
int maxCnt;

int run(int level, int& cut) {

    int ret = 1;
    int check = 0;

    for (int child : arr[level]) {
        if (child == cut) continue;
        check += run(child, cut);
    }

    if (check) return check;
    else return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int root;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num == -1) root = i;
        else arr[num].push_back(i);
    }

    int cut;
    cin >> cut;

    if (root != cut) {
        cout << run(root, cut) << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
