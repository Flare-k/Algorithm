#include <iostream>
using namespace std;

int main(){
    int n = 5, m = 5;
    int data[5] = {1, 2, 3, 2, 3};
    
    int result = 0, summary = 0, end = 0;
    
    for (int start = 0; start < n; start++) {
        while (summary < m && end < n) {
            summary += data[end];
            end++;
        }

        if (summary == m){
            result++;
        }

        summary -= data[start];
    }

    cout << "Result: " << result << '\n';
    
    return 0;
}
