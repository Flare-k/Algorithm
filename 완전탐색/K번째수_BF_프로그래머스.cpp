// K��°��

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> c : commands) {
        vector<int> p(array.begin() + c[0] - 1, array.begin() + c[1]);
        sort(p.begin(), p.end());
        answer.push_back(p[c[2] - 1]);
    }

   return answer;
}

template <typename T>
void print_vector(vector<T> v) {
    for (auto a : v) cout << a << " ";
    cout << endl;
}

int main() {
    auto ans = solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});

    print_vector<int>(ans);  // 5 6 3
    
    return 0;
}