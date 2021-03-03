/*
 >> 9012번
 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

 여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int range;
    cin >> range;
    stack<char> s;
    
    for (int i = 0; i < range; i++) {
        string icon;
        cin >> icon;

        for (int j = 0; j < icon.length(); j++) {
            if (icon[j] == '(' || s.empty())
                s.push(icon[j]);    //push하여 꾹꾹 눌러담음
            else if (s.top() == '(')  //이부분 해석중요
                s.pop();
        }

        if(s.empty()) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        
        while (!s.empty()) {
            s.pop();
        }

    }
    
    return 0;
}
/*
    for(int i=0; i<icon.size(); i++){
        s.push(icon[i]);
        for(int j=0; j<icon.size(); j++){
            if(icon[j] == '('){
                if(icon[0] == ')')
                    count1 = 0;
                else
                    count1++;
            }
            else if(icon[j] == ')'){
                if(icon[-1] == '(')
                    count2 = 0;
                else
                    count2++;
            }
            else if(icon[j] == ' ' || icon[j] == '\n'){
                count1 = -1;
            }
        }
    }
    
    if(count1 == count2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}*/
