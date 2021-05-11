#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 화장실에 들어가기 위해서 각 사람마다 waits 만큼의 시간이 걸린다. 5분, 20분, 1분, 45분, 30분
// 어떤 순서로 들어가야 가장 적게 기다리면서 모두 이용할 수 있을까?

vector<int> waits = {5, 20, 1, 45, 30};

int main() {

    sort(waits.begin(), waits.end());

    int minutes = 0;

    for (int i = 0; i < 5; i++) {
        minutes += (waits[i] *(5 - i - 1));
    }

    cout << minutes;

    return 0;
}