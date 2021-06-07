#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<string> vect;

    int len = str.length();
    int start = 1;
    int end = len - 1;
    while (1) {

        string total = "";

        // 만약 단락 구분이 겹친다면 첫단락 구분자 한칸 전진
        if (end == start) {
            start++;
            end = len - 1;
        }
        
        if (start == len - 1) break;

        // 첫단락
        string s1 = "";
        for (int i = 0; i < start; i++) {
            s1 += str[i];
        }
        
        // 두번째 단락
        string s2 = "";
        for (int i = start; i < end; i++) {
            s2 += str[i];
        }
        
        // 세번째 단락
        string s3 = "";
        for (int i = end; i < len; i++) {
            s3 += str[i];
        }

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        reverse(s3.begin(), s3.end());
        
        vect.push_back(s1 + s2 + s3);
        end--;
    }

    sort(vect.begin(), vect.end());

    cout << vect[0];

    return 0;
}