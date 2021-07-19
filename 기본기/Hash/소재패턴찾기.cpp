#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int main() {

    string arr[6] = {"ABABAB",
                    "CDCDCD",
                    "AGGFHA",
                    "BBFABC",
                    "DDCCDD",
                    "FFDHAS"};

    
    string vec = "";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vec += arr[i][j];
            vec += arr[i][j+1];
            vec += arr[i+1][j];
            vec += arr[i+1][j+1];

            m[vec]++;
            vec = "";
        }
    }

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    string tmp = a + b + c + d;

    cout << m[tmp];

    return 0;
}