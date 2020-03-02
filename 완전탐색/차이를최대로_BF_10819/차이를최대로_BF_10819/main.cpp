/*
[차이를 최대로]
배열 A: 순서만 바꾸는 것이 가능. 즉, 새로운 수를 추가,삭제가 불가능하다.
순서만 바꿔서 차이가 최대가 나오게끔 해야한다.
3 <= N <= 8
모든 순서를 다 만든다음에
|A[0]-A[1]| + |A[1]-A[2]| + ... + |A[N-2]-A[N-1]|
값을 계산한다고 해도 크게 1억을 넘지 않음. O(N*N!)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int calculate(vector<int>& a){
    int temp = 0;
    for(int i=0; i<a.size()-1; i++){
        temp += abs(a[i] - a[i+1]);
    }
    return temp;
}

int main(){
    int n, ans=0;
    cin>>n;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    do{
        int temp = calculate(a);
        ans = max(ans, temp);
    }while(next_permutation(a.begin(), a.end()));
    
    cout<<ans<<'\n';
    
    return 0;
}
