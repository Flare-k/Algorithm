#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool compare(tuple<string, int, int, int>& a, tuple<string, int, int, int>& b){
    if (get<1>(a) > get<1>(b))
        return true;
    else if (get<1>(a) == get<1>(b)) {
        if (get<2>(a) < get<2>(b))
            return true;
        else if (get<2>(a) == get<2>(b)) {
            if (get<3>(a) > get<3>(b))
                return true;
            else if (get<3>(a) == get<3>(b))
                return get<0>(a) < get<0>(b);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<tuple<string, int, int, int>> student;
    int n; 
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string name;
        int kor, eng, math;

        cin >> name >> kor >> eng >> math;
        student.push_back(make_tuple(name, kor, eng, math));
    }
    
    sort(student.begin(), student.end(), compare);
    
    for (int i = 0; i < n; i++) {
        cout << get<0>(student[i]) << '\n';
    }
    
    return 0;
}
