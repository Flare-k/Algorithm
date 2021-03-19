//재귀함수 이용
/*
1.불가능한 경우
    - 합이 goal 보다 커질 때. sum>goal
2.정답을 찾은 경우
    - 진짜로 정답을 찾아서 정답에 무언가를 더해주거나 더이상 함수를 호출하지 않는..
    - 합이 goal이 되면 됨.
3.다음 경우 호출
    - 1을 사용하는 경우. -> go(count+1, sum+1, goal)
    - 2를 사용하는 경우. -> go(count+1, sum+2, goal)
    - 3을 사용하는 경우. -> go(count+1, sum+3, goal)
*/
#include <iostream>
using namespace std;

int go(int count, int sum, int goal) {
    if (sum > goal) return 0; //불가능한 경우
    if (sum == goal) return 1; //정답 하나를 찾은 것이므로 1을 리턴
    
    int now = 0;

    for (int i = 1; i <= 3; i++) {
        now += go(count + 1, sum + i, goal);
    }
    
    return now;
    //O(3^n)  함수의 깊이는 n을 넘을 수 없다.
    //count는 지워도 상관없다.
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << go(0, 0, a) << '\n';
    }
    
    return 0;
    
}
