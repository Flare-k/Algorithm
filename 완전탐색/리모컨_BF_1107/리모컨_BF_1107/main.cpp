#include <iostream>
#include <string>
using namespace std;
const int MAX= 10000001;
int arr[MAX];
int fuck[MAX];

int main() {
    string channel;
    int round;
    int result = 100;
    
    cin>>channel>>round;
    
    for(int i=0; i<channel.size(); i++){
        arr[i] = channel[i] - '0';
    }   //5457 배열로 저장
    
    for(int i=0; i<round; i++){
        cin>>fuck[i];
    }   //고장난 채널 입력
    
    while(1){
        if(channel == "100"){
            cout<<'0'<<'\n';
            break;
        }
        else{
            
        }
    }
    
    return 0;
}
