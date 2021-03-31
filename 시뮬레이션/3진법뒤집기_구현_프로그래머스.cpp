#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(int n) {

    stack<int> tmp;
    while (n != 0) {
        tmp.push(n % 3);
        n /= 3;
    }

    int sum = 0;
    int idx= 1;
    while (!tmp.empty()) {
        sum += (tmp.top() * (idx));
        idx *= 3;
        tmp.pop();
    }

    return sum;
}

int main() {
    
    cout << solution(45);

    return 0;
}