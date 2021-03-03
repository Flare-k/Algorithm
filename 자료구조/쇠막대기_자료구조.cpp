#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int solution(string arrangement) {
    stack<char> s;
    int cnt = 0;
  
    for (int j = 0; j < arrangement.length(); j++) {
        if (arrangement[j] == '(' || s.empty()) {
            s.push(arrangement[j]);    //push하여 꾹꾹 눌러담음
        }
        else if (s.top() == '(') {  //이부분 해석중요
            s.pop();
            if (arrangement[j - 1] == '(') 
                cnt+=s.size();
            else
                cnt++;
        }
    }

    return cnt;
}

int main(){
    string icon;
    cin >> icon;
    
    cout << solution(icon) << endl;
    
    return 0;
}

