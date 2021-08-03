#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> answer;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin.ignore();   // N을 입력할때 들어간 \n을 없애준다. (뒤이어 getline 쓰려면 중요)

    while (N--) {
        string str;
        getline(cin, str);

        str[0] = toupper(str[0]);
        answer.push_back(str);
    }


    for (auto a : answer) {
        cout << a << '\n';
    }

    return 0;
}