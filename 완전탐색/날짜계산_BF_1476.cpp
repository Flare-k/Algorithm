#include <iostream>
using namespace std;

int main(){
    int earth,sun,moon;
    cin >> earth >> sun >> moon;
    
    int e = 1, s = 1, m = 1; //1년이 제일 초기값임을 의미.
    
    for (int i = 1; ; i++) {
        if (earth == e && sun == s && moon ==m) {
            cout << i << '\n';
            break;
        }

        e += 1;
        s += 1;
        m += 1;
        
        if (e == 16) e = 1;        //16이 되면 다시 1로 초기화
        if (s == 29) s = 1;
        if (m == 20) m = 1;
    }
    
    return 0;
}


/* 모드로 푸는 방법
 int main(){
 int e,s,m;
 cin>>e>>s>>m;
 e -= 1;
 s -= 1;
 m -= 1;
 for(int i=0;;i++){
    if(i%15 == e && i%28 == s && i%19 == m){
        cout<<i+1<<endl;
        break;
    }
 }
}
 */
