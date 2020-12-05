#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define endl "\n"
using namespace std;

const int MAX = 1000000;
int prime[MAX]={0};
bool visit[MAX+1];
vector<int> prime_vec;

void go(){
    prime[0] = prime[1] = 0;
    visit[0] = visit[1] = true;
    
    for(int i = 2; i <= MAX; i++){
        prime[i] = i; //MAX만큼 배열에 모두 초기화 해준다.
    }
    
    for (int i = 2; i <= MAX; i++){
        if(visit[i] == false){
            prime_vec.push_back(i);
            
            for(int j = i + i; j <= MAX; j += i){
                visit[j] = true;
                prime[j] = 0;
            }
        }
    }
    // 100,000 까지의 소수 정리.
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    go();
    int n;
    while(cin >> n && n != 0){
        bool check = false;
        
        for (int i = 0; prime_vec[i] < n; i++){
            int a = prime_vec[i];
            int b = n - prime_vec[i];
            
            if(!visit[b]){
                cout << n << " = " << a << " + " << b << endl;
                check = true;
                break;
            }
        }

        if(!check){
            cout<<"Goldbach's conjecture is wrong."<<endl;
        }
    }
    
    return 0;
}