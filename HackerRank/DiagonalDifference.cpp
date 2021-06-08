#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int diagonalDifference(vector<vector<int>> arr) {
    int left = 0;
    int right = 0;
    
    int idx = 0;
    for (int i = 0; i < arr.size(); i++) {
        left += arr[i][idx++];
    }
    
    idx = arr.size() - 1;
    for (int i = 0; i < arr.size(); i++) {
        right += arr[i][idx--];
    }
    
    return abs(left - right);
}
