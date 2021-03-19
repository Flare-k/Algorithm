#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//재귀함수 이용
bool check(string &password) {
    int ja = 0;
    int mo = 0;

    for (char x : password) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            mo += 1;
        }
        else {
            ja += 1;
        }
    }

    return ja >= 2 && mo >= 1;
}


void go(int n, vector<char> &alpha, string password, int i) {
    if (password.length() == n) {
        if (check(password)) {
            cout << password << '\n';
        }
        
        return;
    }

    if (i >= alpha.size()) return;    //맨앞에 오면 오류가 날 수 있다.
    
    go(n, alpha, password + alpha[i], i + 1);   //i번째 알파벳 사용
    go(n, alpha, password, i + 1);            //i번째 알파벳 사용 안 함

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int l, c;   // l=선택할 개수, c=입력 개수
    cin >> l >> c;
    
    vector<char> alphabet;
    
    char alpha;

    for (int i = 0; i < c; i++) {
        cin >> alpha;
        alphabet.push_back(alpha);
    }
    
    sort(alphabet.begin(), alphabet.end());     //c개수 만큼 알파벳을 벡터에 입력
    
    go(l, alphabet, "", 0);
    
    return 0;
}
// a c i s t w
