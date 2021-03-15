#include <iostream>
using namespace std;

struct Node {
    int num;
    char str;
};

int cmp(Node a, Node b) {
    if (a.num < b.num) return 1;
    if (a.num > b.num) return 0;
    if (a.num == b.num) {
        if (a.str < b.str) 
            return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    Node arr[n];
    Node res[n];

    for (int i = 0; i < n; i++) {
        int num;
        char str;
        cin >> arr[i].num >> arr[i].str;
    }

    
    for (int i = 0; i < n; i++) {
        int idx = i;

        res[idx] = arr[idx];

        for (int j = idx; j > 0; j--) {
            Node n1 = res[j - 1];
            Node n2 = res[j];

            if (cmp(n1, n2) == 0) {
                swap(res[j - 1], res[j]);
            }
            else {
                break;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        cout << res[i].num << ' ' << res[i].str << '\n';
    }

    return 0;
}