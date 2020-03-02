#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 첫 순열 만들기
 다음 순열 반복
 마지막 순열 도출
 do-while은 거의 모든수열을 구할 때만 사용한다.
 */
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }
    
    
    do{
        for(int i=0; i<n; i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }while(next_permutation(a.begin(), a.end()));   //알아서 1 2 3의 다음순열을 뱉어줌
    
    return 0;
}
