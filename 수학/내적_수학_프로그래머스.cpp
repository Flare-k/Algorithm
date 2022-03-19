#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    int size = a.size();

    for (int i = 0; i < size; i++) {
        answer += (a[i] * b[i]);
    }

    return answer;

}

int main () {
    
    vector<int> a;

    for (int i = 0 ; i < 4; i++) {
        a.push_back(i + 1);
    }

    vector<int> b;

    b.push_back(-3);
    b.push_back(-1);
    b.push_back(0);
    b.push_back(2);

    cout << solution(a, b);
}