/*
 경우의 수는 총 2**n개 나오고 모두 구한 후 합을 구해주면 된다.
 
 index: 부분집합에 포함할지 말지 결정해야 하는 인덱스
 sum: 현재까지 부분집합의 합
 
 n개의 수 중에 합이 m이 되는 경우를 찾아라!
 1. 정답을 찾은 경우: sum == m
 2. 불가능한 경우: index == n
 3. 다음경우호출: 부분집합에 포함, 포함하지 않는다.
 
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, s;
int answer = 0;

void go(int index, int sum) {
    if (index == n) {
        if (sum == s) {
            answer += 1;
        }
        
        return;
    }
    
    go(index + 1, sum + arr[index]);
    go(index + 1, sum);

}

int main() {
    cin >> n >> s;

    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    go(0, 0);

    if(s == 0) answer -= 1; //공집합을 제외
    //공집합은 아무것도 없는 경우라서 합이 0이 나온다. 그러면 항상 go(index+1, sum)이 함수만 선택하면 합이 0이 나올 것.
    //그래서 문제에서 구하라고 하는 합이 0일 때만 공집합의 합을 빼준다.
    cout << answer << endl;
    
    return 0;
}
