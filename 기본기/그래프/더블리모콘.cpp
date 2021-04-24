#include <iostream>
#include <queue>
using namespace std;

//현재 채널에서 목표 채널로 이동할 수 있는 최소 버튼 클릭 회수를 출력
// 채널을 변경할 때는 네개의 버튼만 클릭 가능하다. /2 *2 +1 -1
// BFS로 모든 경우의 수를 다 관리해보자

struct Button {
    int level;
    int value;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start, target;
    cin >> start >> target;

    queue<Button> button;

    button.push({1, start});
    
    while (!button.empty()) {
        Button now = button.front();
        button.pop();

        button.push({now.level + 1, now.value / 2});
        button.push({now.level + 1, now.value * 2});
        button.push({now.level + 1, now.value + 1});
        button.push({now.level + 1, now.value - 1});

        if (now.value / 2 == target) {
            cout << now.level;
            break;
        }
        else if (now.value * 2 == target) {
            cout << now.level;
            break;
        }
        else if (now.value + 1 == target) {
            cout << now.level;
            break;
        }
        else if (now.value - 1 == target) {
            cout << now.level;
            break;
        }
    }
    

    return 0;
}