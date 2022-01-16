#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, pivot;
string A, B;
int arr[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};


int run(vector<int> v) {
    if (v.size() == 2) {
        int num = v.front() * 10 + v.back();
        return num;
    }

    vector<int> tmp;
    for (int i = 0; i < v.size() - 1; i++) {
        tmp.push_back((v[i] + v[i + 1]) % 10);
    }

    return run(tmp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> A >> B;

    pivot = min(N, M);
    string str = "";

    for (int i = 0; i < pivot; i++) {
        str += A[i]; 
        str += B[i];
    }

    if (A.length() > B.length()) str += A.substr(pivot);
    else if (A.length() < B.length()) str += B.substr(pivot);

    vector<int> v;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        v.push_back(arr[str[i]-'A']);
    }

    cout << run(v) << "%";

    return 0;
}