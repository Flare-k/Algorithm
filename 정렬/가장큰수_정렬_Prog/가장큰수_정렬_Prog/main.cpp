#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    
    sort(numbers.begin(), numbers.end());
    for(int i=0; i<numbers.size(); i++){
        temp.push_back(to_string(numbers[i]));
    }
    sort(temp.begin(), temp.end(), cmp);

    
    if (temp.at(0) == "0")
        return "0";
    for(int i=0; i<temp.size(); i++){
        answer += temp[i];
    }
    
    return answer;
   
}

int main() {
    vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(30);
    numbers.push_back(34);
    numbers.push_back(5);
    numbers.push_back(9);
    
    cout<<solution(numbers)<<'\n';
    
    return 0;
}
