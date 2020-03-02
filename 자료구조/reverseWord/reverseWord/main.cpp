#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
//스택을 이용한 단어 뒤집기
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int num;
    cin>>num;
    stack<char> s;
    
    string command;
    getline(cin, command); //[중요!!] 남은 버퍼를 먼저 비워줘야 한다.

    for(int i=0; i<num; i++){
        string sentence;
        getline(cin, sentence); //한 문장을 입력받을 경우.
        sentence += '\n';   //여러 줄일 경우 줄과 줄을 구분하기 위해 추가.
        
        for(int j=0; j<sentence.size(); j++){
            if(sentence[j] == ' ' || sentence[j] == '\n'){
                while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }
                cout<<" ";
            }
            else
                s.push(sentence[j]);
        }
        cout<<'\n';
    }
    return 0;
}
/*
 # 띄어쓰기를 포함하여 통째로 입력을 저장하는 방법2(줄 바꿈 문자를 제외하고 입력받음)

 * 어떤 데이터형(int or char)과 string형을 연달아 입력받을 때 getline 버퍼에 입력된 줄바꿈 문자를 받아들여 버리는데
   이를 막기위해서 사이에 getchar()를 삽입해줄 수 있다.

 - scanf() (scanf는 앞뒤 공백을 무시하므로 한줄 전체를 그대로 받는 데에는 적절치 못하다.)

 - getline() string을 사용할 수 있어서 가장편리함
 */
