#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 go(a, index, cnt)
 a: 입력으로 주어진 수
 index: 선택할지 말지 결정해야 하는 인덱스
 cnt: 현재까지 포함한 수의 개수
 
 1. 정답: cnt == 6인 경우
 2. 불가능: index >= a의 크기
 3. 다음 경우: 1) 포함하는 경우
             2) 포함하지 않는 경우
 
 */
int n; // 테스트 케이스 갯수
vector<int> lotto;
void go(vector<int> &a, int index, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < lotto.size(); i++) {
            cout << lotto[i] << ' ';
        }

        cout << '\n';
        return;
    }

    if (index >= a.size()) return;
    
    lotto.push_back(a[index]);
    go(a, index + 1, cnt + 1);
    lotto.pop_back();       // 여기까지 index번째를 선택하는경우
    
    go(a, index + 1, cnt);  //선택하지 않는 경우
}

int main() {
    while (cin >> n && n) {
        vector<int> inputvec;
        vector<int> checkvec;

        int num;
        
        for (int i = 0; i < n; i++) {
            cin >> num;
            inputvec.push_back(num);
        }
        
        go(inputvec, 0, 0);
    }
    
    return 0;
}
