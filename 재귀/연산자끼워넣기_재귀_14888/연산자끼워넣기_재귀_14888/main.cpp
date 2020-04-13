/*
 go(a, index, cur, plus, minus, mul, div)
 a: 입력으로 주어진 배열
 index: 현재 계산해야 하는 인덱스
 cur: index-1번째까지 계산한 결과
 plus~div: 사용할 수 있는 연산자 개수
 
 1. 정답을 찾은 경우: index == a의크기-1
 2. 불가능한 경우: plus  < 0 || minus <0 ...
 3. 다음경우 : 1) plus사용 -> go(a, index+1, cur+a[index], plus-1, minus, ..)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[20];

pair<int, int> go(vector<int>& a, int index, int cur, int plus, int minus, int mul ,int div){
    if(index == a.size())
        return make_pair(cur, cur);
    vector<pair<int, int>> res;
    
    if(plus > 0){
        res.push_back(go(a, index+1, cur+a[index], plus-1, minus, mul, div));
    }
    if(minus > 0){
        res.push_back(go(a, index+1, cur-a[index], plus, minus-1, mul, div));
    }
    if(mul > 0){
        res.push_back(go(a, index+1, cur*a[index], plus, minus, mul-1, div));
    }
    if(div > 0){
        res.push_back(go(a, index+1, cur/a[index], plus, minus, mul, div-1));
    }
    auto ans = res[0];
    for(auto p : res){
        if(ans.first < p.first){
            ans.first = p.first;
        }
        if(ans.second > p.second){
            ans.second = p.second;
        }
    }
    return ans;
}


int main() {
    int n;
    cin>>n;
    vector<int> a;
    vector<int> oper;
    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        a.push_back(num);
    }
    int plus, minus, mul, div;
    cin>>plus>>minus>>mul>>div;
    auto p = go(a, 1,a[0],plus,minus,mul,div);
    cout<<p.first<<'\n';
    cout<<p.second<<'\n';
    
    return 0;
}
