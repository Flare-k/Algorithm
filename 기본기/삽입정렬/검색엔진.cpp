#include <iostream>
#include <vector>
#include <string>
using namespace std;

// flag를 이용하는 방법도 생각해보자

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> dic = {"ABCD", "ABCE", "AGEH", "EIEI", "FEQE", "ABAD"};

    string search;
    cin >> search;

    int cntQ = 0;
    for (int i = 0; i < search.length(); i++) {
        if (search[i] != '?') cntQ++;
    }

    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        int checkQuest = 0;
        for (int j = 0; j < search.length(); j++) {
            if (search[j] != '?') {
                if (search[j] == dic[i][j]) checkQuest++;
            }
        }

        if (cntQ == checkQuest) cnt++;
        
    }

    cout << cnt;

    return 0;
}