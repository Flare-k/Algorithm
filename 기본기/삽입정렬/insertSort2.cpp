#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
      개념 체크용으로 배열은 임의로 하드코딩
    */
    float vect[6] {8.9, 7, 8.2, 9.3, 9.2, 7.6};
    float res[4] {0, };

    for (int i = 0 ; i < 6; i++) {
        int idx = i;
        if (idx > 4) idx = 3;
        
        res[idx] = vect[i];    
        
        for (int j = idx; j > 0; j--) {
            if (res[j - 1] < res[j]) {
                swap(res[j - 1], res[j]);
            }
            else {
                break;
            }
        }
    }

    for (int i = 0 ; i < 4; i ++) {
        cout << res[i] << ' ';
    }

    return 0;
}