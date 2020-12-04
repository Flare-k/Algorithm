#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int MAX = 1000000;
int visited[MAX];
vector<int> point[MAX];
int num, p;

void dfs(int num){
    visited[num] += 1;

    if(visited[num] >= 3) return;
    int sum = 0;
    
    while(num){
        sum += pow(num % 10, p);
        num /= 10;
    }
    dfs(sum);
}


int main() {
    cin >> num >> p;
    
    dfs(num);

    int ans = 0;
    
    for(int i = 0; i < MAX; i++){
        if(visited[i] == 1)
            ans += 1;
    }

    cout << ans << '\n';

    return 0;
}
