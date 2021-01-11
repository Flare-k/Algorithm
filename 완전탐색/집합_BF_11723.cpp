#include <iostream>
#include <bitset>
using namespace std;

int main() {
    
    cout << (1 << 2) << endl;
    
    return 0;
}


/*
 공집합을 제외한 전체집합?
 for(int i=1; i<(1<<n); i++{
 }
 
 집합에 무엇이 포함되어 있는지 확인하려면?
 for(int i=1; i<(1<<n); i++{
    for(int k=0; k<n; k++){
        if(i&(1<<k)){
        }
    }
 }
 */
