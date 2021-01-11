#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int calc(vector<int> a, vector<int> operate) {
    int sum = a[0];

    for (int i = 1; i < a.size(); i++) {  //연산자는 피연산자의 한개덜필요함
        if (operate[i-1] == 0) sum += a[i];
        else if (operate[i-1] == 1) sum -= a[i];
        else if (operate[i-1] == 2) sum *= a[i];
        else sum /= a[i];
    }
    
    return sum;
}

int main(){
    int num;
    cin >> num;   //입력할 수의 개수

    vector<int> a;
    
    int sample1;

    for (int i = 0; i < num; i++) {
        cin >> sample1;       //연산하고 싶은 수
        a.push_back(sample1);
    }
    
    vector<int> operate;
    for (int i = 0; i < 4; i++) {
        int cnt;
        cin >> cnt;   //각 연산자의 개수를 입력
        
        for (int k = 0; k < cnt; k++) {   //0, 1, 2, 3의 숫자가 본인의 개수만큼 들어감
            operate.push_back(i);
        }
    }

    sort(operate.begin(), operate.end());
    
    vector<int> result;

    do {
        int temp = calc(a, operate);
        result.push_back(temp);
    } while(next_permutation(operate.begin(), operate.end()));
    
    auto ans = minmax_element(result.begin(), result.end());

    cout << *ans.second << '\n';
    cout << *ans.first << '\n';
    
    return 0;
}
