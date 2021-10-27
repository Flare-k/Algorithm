#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string input;
    int num;
    
    cin >> input;
    
    stack<char> output;
    stack<char> answer;
    
    for (int i = 0; i < input.size(); i++) {
        output.push(input[i]);
    }

    cin >> num;
    
    string result = "";

    while (num--) {
        char in;
        cin >> in;

        if (in == 'L') {  //커서를 왼쪽으로 한 칸
            if (!output.empty()) {
                answer.push(output.top());
                output.pop();
            }
        }
        else if (in == 'D') { //커서를 오른쪽으로 한 칸
            if (!answer.empty()) {
                output.push(answer.top());
                answer.pop();
            }
        }
        else if (in == 'B') { //커서 왼쪽에 있는 문자 삭제
            if (!output.empty()) output.pop();
        }
        else if (in == 'P') { //왼쪽에 ptr 문자 추가
            char ptr; 
            cin >> ptr;
            
            output.push(ptr);
        }
    }
    
    while (!output.empty()) {
        answer.push(output.top());
        output.pop();
    }

    while (!answer.empty()) {
        result += answer.top();
        answer.pop();
    }

    cout << result << '\n';
    
    return 0;
}
