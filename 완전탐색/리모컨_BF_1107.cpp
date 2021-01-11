#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 1000001;
int malFunc[MAX];

bool malFuncCheck(int num){
    string channel = to_string(num);
    for (int i = 0; i < channel.length(); i++){
        // 만약 고장난 버튼이라면? false
        if(malFunc[channel[i] - '0']){
            return false;
        }
    }
    return true;
}


int main() {
    int channel, n; // 이동하려는 채널, 고장난 버튼 수
    
    cin >> channel;
    cin >> n;

    for (int i = 0; i < n ; i++){
        int a;
        cin >> a;
        malFunc[a] = true;  // 고장난 버튼이라면 true!
    }

    int minChannel = abs(channel - 100);
    for (int i = 0; i < MAX; i++){
        if (malFuncCheck(i)){
            int tmp = abs(channel - i) + to_string(i).length();
            // 입력한 채널과 경우의 수에 있는 채널에 대한 연산.. 
            //둘의 차 = + or - 횟수 & 경우의 채널 길이
            minChannel = min(minChannel, tmp);
        }
    }

    cout << minChannel << '\n';
    
    return 0;
}
