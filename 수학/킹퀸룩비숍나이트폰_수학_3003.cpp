#include <iostream>
using namespace std;

int king = 1;
int queen = 1;
int rook = 2;
int bishop = 2;
int knight = 2;
int pawn = 8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int _king, _queen, _rook, _bishop, _knight, _pawn;
    cin >> _king >> _queen >> _rook >> _bishop >> _knight >> _pawn;

    cout << (king - _king) << ' ' << (queen - _queen) << ' ' << (rook - _rook) << ' ' << (bishop - _bishop) << ' ' << (knight - _knight) << ' ' << (pawn - _pawn);

    return 0;
}