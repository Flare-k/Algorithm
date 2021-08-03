#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> var;

void split(string cmd) {
    int cnt = 0;
    int left = 0;
    int right = 1;
    string tmp;

    while (1) {
        right = cmd.find(" ", left);

        if (right == -1) {
            tmp = cmd.substr(left);
            tmp.pop_back();

            var.push_back(tmp);
            break;
        }
        else {
            cnt++;
            tmp = cmd.substr(left, right - left);
            
            if (cnt > 1) tmp.pop_back();

            var.push_back(tmp);
            left = right + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string cmd;
    getline(cin, cmd);
    split(cmd);

    for (int i = 1; i < var.size(); i++) {
        string tmp = "";
        // 기호 편집
        int j;
        for (j = var[i].length() - 1; j > 0; j--) {
            if (var[i][j] == '[') var[i][j] = ']';
            else if (var[i][j] == ']') var[i][j] = '[';

            if (var[i][j] == '&' or var[i][j] == '*' or var[i][j] == '[' or var[i][j] == ']') tmp += var[i][j];
            else break;
        }
        
        // 변수 편집
        string tmpValue = "";
        for (int k = 0; k <= j; k++) {
            tmpValue += var[i][k];
        }

        tmp = tmp + " " + tmpValue;

        var[i] = tmp;
        
        cout << var.front() << var[i] << ";\n";
    }


    return 0;
}