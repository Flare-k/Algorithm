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

    // 정렬된 결과를 저장하기 위한 벡터
    vector<string> vect;

    int len = str.length();
    int start = 1;  
    int end = len - 1;
    while (1) {

        // 만약 단락 구분이 같아진다면 start는 늘리고 end는 다시 초기화
        if (end == start) {
            start++;
            end = len - 1;
        }
        
        if (start == len - 1) break;

        string s1 = str.substr(0, start);           // 첫번째 단락
        string s2 = str.substr(start, end - start);         // 두번째 단락
        string s3 = str.substr(end);  // 세번째 단락
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        reverse(s3.begin(), s3.end());

        // 결과 저장
        vect.push_back(s1 + s2 + s3);

        // 세번째 단락을 늘리고 두번째 단락은 줄이며 반복진행
        end--;
    }

    sort(vect.begin(), vect.end());

    cout << vect[0];

    return 0;
}