#include <iostream>
#include <stack>
#include <string>
#define endl "\n"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        string s;
        getline(cin, s);

        stack<char> brac;

        if (s.size() == 1 && s[0] == '.') break;

        bool check = false;

        for (int i = 0; i < s.size(); i++) {
            
            if (s[i] == '[' || s[i] == '(') {
                brac.push(s[i]);
            } 
            else if (s[i] == ')') {
                if (brac.size() > 0 && brac.top() == '('){
                    brac.pop();
                }
                else {
                    check = true;
                    break;
                }
            } 
            else if (s[i] == ']') {
                if (brac.size() > 0 && brac.top() == '['){
                    brac.pop();
                }
                else {
                    check = true;
                    break;
                }
            }
        }
        
        if (brac.empty() && !check)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    
    return 0;
}

