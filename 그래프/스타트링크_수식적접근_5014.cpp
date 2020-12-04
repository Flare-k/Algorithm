#include <algorithm>
#include <iostream>

using namespace std;

// 수학적인 방식으로 접근하기

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int total, current, destination, up, down;  // 총 층수, 현재 층수, 도착 층수, Up, Down
    cin >> total >> current >> destination >> up >> down;  // 10 1 10 2 1

    for (int cnt = 0; cnt < 1000000; cnt++){
        if (current == destination){    // 도착지에 왔다면 횟수 출력
            cout << cnt << '\n';
            return 0;
        }

        // 1) 모든 경우가 안 되는 케이스
        // 현재 층 + Up이 총 층수보다 크고 현재 층 - Down이 1보다 작으면 멈춘다
        if (current + up > total && current - down < 1) break;

        if (current + up <= total && current < destination)  // 2) Up인 케이스
            current += up;
        else if (!(current > destination && current - down < 1))  // 3) Down인 케이스
            current -= down;
    } 
    cout << "use the stairs" << '\n';
    
    return 0;
}