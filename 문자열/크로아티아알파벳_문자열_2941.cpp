#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool coroatiaCheck(string s) {
    if (s == "c=")
        return true;
    else if (s == "c-")
        return true;
    else if (s == "dz=")
        return true;
    else if (s == "d-")
        return true;
    else if (s == "lj")
        return true;
    else if (s == "nj")
        return true;
    else if (s == "s=")
        return true;
    else if (s == "z=")
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string ss;
    cin >> ss;

    int i = 0;
    int cnt = 0;

    while (1) {
        if (i == ss.length()) break;

        string temp2 = "";
        string temp3 = "";
        temp2 += ss.substr(i, 2);
        temp3 += ss.substr(i, 3);

        if (coroatiaCheck(temp2)) {
            cnt++;
            i += 2;
        } 
        else if (coroatiaCheck(temp3)) {
            cnt++;
            i += 3;
        } 
        else {
            cnt++;
            i++;
        }
    }
    cout << cnt;
    return 0;
}