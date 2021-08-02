#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

int t, n;
char color[6] = {'w', 'r', 'y', 'g', 'b', 'o'};
char arr[6][3][4];
char tmp[3][4];
unordered_map<char, int> m;

enum {
    U, F, D, L, R, B
};

void init() {
    m['U'] = U;
    m['F'] = F;
    m['D'] = D;
    m['L'] = L;
    m['R'] = R;
    m['B'] = B;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[U][i][j] = color[U];
            arr[F][i][j] = color[F];
            arr[D][i][j] = color[D];
            arr[L][i][j] = color[L];
            arr[R][i][j] = color[R];
            arr[B][i][j] = color[B];
        }
    }    
    
}

// 현재 면 좌 또는 우로 돌리기
void turnCubeK(char sq, char dir) {
    memset(tmp, 0, sizeof(tmp));
    int k = m[sq];
    if (dir == '+') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = arr[k][2 - j][i];
            }
        }
        
        memcpy(arr[k], tmp, sizeof(tmp));
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[2 - j][i] = arr[k][i][j];
            }
        }
        
        memcpy(arr[k], tmp, sizeof(tmp));
    }
}

// 인접한 면 돌리기
void turnCubeSur(char sq, char dir) {
    char tmpRow[4];
    fill(tmpRow, tmpRow + 4, 0);

    if (sq == 'U') {
        if (dir == '+') { // F->L->B->R->F (1행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[L][0][i];
                arr[L][0][i] = arr[F][0][i];
                arr[F][0][i] = arr[R][0][i];
                arr[R][0][i] = arr[B][0][i];
                arr[B][0][i] = tmpRow[i];
            }
        }
        else { // F<-L<-B<-R<-F
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[L][0][i];
                arr[L][0][i] = arr[B][0][i];
                arr[B][0][i] = arr[R][0][i];
                arr[R][0][i] = arr[F][0][i];
                arr[F][0][i] = tmpRow[i];
            }
        }
    }
    else if (sq == 'D') { 
        if (dir == '+') { //F(3행)-R(3열)-B(1행)-L(1열)-F(3행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[L][2][i];
                arr[L][2][i] = arr[B][2][i];
                arr[B][2][i] = arr[R][2][i];
                arr[R][2][i] = arr[F][2][i];
                arr[F][2][i] = tmpRow[i];
            }
        }
        else {            //F(3행)-L(1열)-B(1행)-R(3열)-F(3행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[L][2][i];
                arr[L][2][i] = arr[F][2][i];
                arr[F][2][i] = arr[R][2][i];
                arr[R][2][i] = arr[B][2][i];
                arr[B][2][i] = tmpRow[i];
            }
        }
    }
    else if (sq == 'F') {
        if (dir == '+') { //U(3행)-R(3행)-D(1행)-L(3행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][2][i];
                arr[U][2][i] = arr[L][2 - i][2];
                arr[L][2 - i][2] = arr[D][0][2 - i];
                arr[D][0][2 - i] = arr[R][i][0];
                arr[R][i][0] = tmpRow[i];
            }
        }
        else {            //L(3행)-D(3행)-R(1행)-U(3행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][2][i];
                arr[U][2][i] = arr[R][i][0];
                arr[R][i][0] = arr[D][0][2 - i];
                arr[D][0][2 - i] = arr[L][2 - i][2];
                arr[L][2 - i][2] = tmpRow[i];
            }
        }
    }
    else if (sq == 'B') {
        if (dir == '+') { //U(1행)-L(1행)-D(3행)-R(1행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][0][i];
                arr[U][0][i] = arr[R][i][2];
                arr[R][i][2] = arr[D][2][2 - i];
                arr[D][2][2 - i] = arr[L][2 - i][0];
                arr[L][2 - i][0] = tmpRow[i];
            }
        }
        else {            //L(3행)-R(3행)-D(1행)-L(3행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][0][i];
                arr[U][0][i] = arr[L][2 - i][0];
                arr[L][2 - i][0] = arr[D][2][2 - i];
                arr[D][2][2 - i] = arr[R][i][2];
                arr[R][i][2] = tmpRow[i];
            }
        }
    }
    else if (sq == 'L') {
        if (dir == '+') { //U(1열)-F(1열)-D(1열)-B(1열)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][i][0];
                arr[U][i][0] = arr[B][2 - i][2];
                arr[B][2 - i][2] = arr[D][i][0];
                arr[D][i][0] = arr[F][i][0];
                arr[F][i][0] = tmpRow[i];
            }
        }
        else {            //U(1열)-B(1열)-D(1열)-F(1열)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][i][0];
                arr[U][i][0] = arr[F][i][0];
                arr[F][i][0] = arr[D][i][0];
                arr[D][i][0] = arr[B][2 - i][2];
                arr[B][2 - i][2] = tmpRow[i];
            }
        }
    }
    else if (sq == 'R') {
        if (dir == '+') { //U(3열)-B(3열)-D(3열)-F(3열)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][i][2];
                arr[U][i][2] = arr[F][i][2];
                arr[F][i][2] = arr[D][i][2];
                arr[D][i][2] = arr[B][2 - i][0];
                arr[B][2 - i][0] = tmpRow[i];
            }
        }
        else {            //L(3행)-R(3행)-D(1행)-L(3행)
            for (int i = 0; i < 3; i++) {
                tmpRow[i] = arr[U][i][2];
                arr[U][i][2] = arr[B][2 - i][0];
                arr[B][2 - i][0] = arr[D][i][2];
                arr[D][i][2] = arr[F][i][2];
                arr[F][i][2] = tmpRow[i];
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        init();


        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;
            turnCubeK(cmd.front(), cmd.back());
            turnCubeSur(cmd.front(), cmd.back());
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << arr[U][i][j];
            }
            cout << '\n';
        }

    }


    return 0;
}