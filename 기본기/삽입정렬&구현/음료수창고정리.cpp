#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> board;

    for (int i = 0; i < 5; i++) {
        string bottle;
        cin >> bottle;
        board.push_back(bottle);
    }

    int first, second;
    cin >> first >> second;

    sort(board[first].begin(), board[first].end());
    sort(board[second].begin(), board[second].end());

    for (int i = 0 ; i < board.size(); i++) {
        cout << board[i][0] << ' ';
    }

    return 0;
}