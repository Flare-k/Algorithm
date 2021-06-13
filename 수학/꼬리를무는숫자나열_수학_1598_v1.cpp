#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<Node> node;

    for (int i = 0; i < 2; i++){
        int num;
        cin >> num;

        int idx = 1;
        for (int j = 1; ; j += 4) {
            if (num >= j && num <= j + 3) {
                node.push_back({idx, num - j + 1});
                break;
            }
            idx++;
        }
    }

    int row = abs(node[0].x - node[1].x);
    int col = abs(node[0].y - node[1].y);

    cout << row + col;

    return 0;
}