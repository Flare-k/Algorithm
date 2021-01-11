#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> before;
    vector<string> tmp1;
    vector<string> tmp2;

    for (int k = 0; k < n; k++) {
        for (int i = n - 1; i >= 0; i--) {
            tmp1.push_back(arr1[k] >> i & 1 ? "#" : " ");
            tmp2.push_back(arr2[k] >> i & 1 ? "#" : " ");
        }
    }

    for (int i = 0; i < tmp1.size(); i++) {
        if (tmp1[i] == "#" && tmp2[i] =="#")
            before.push_back("#");
        else if (tmp1[i] == "#" && tmp2[i] ==" ")
            before.push_back("#");
        else if (tmp1[i] == " " && tmp2[i] =="#")
            before.push_back("#");
        else
            before.push_back(" ");
    }
    
    for (int i = 0; i < n; i++) {
        string tmp="";
        for (int j = i * n; j < (i + 1) * n; j++) {
            tmp += before[j];
        }
        answer.push_back(tmp);
    }
        

    return answer;
}

int main() {
    vector<int> a{9,20,28,18,11};
    vector<int> b{30, 1, 21, 17, 28};

    int size = a.size();

    for (int i = 0; i < solution(size, a, b).size(); i++) {
        cout << solution(size, a, b)[i] << ' ';
    }
    
}

/*
 for(int k=0; k<b.size(); k++){
     string temp = "";
     for (int i = 4; i >= 0; i--){
         cout<<(b[k] >> i & 1 ? 1 : 0);
         if(to_string(b[k] >> i & 1 ? 1 : 0) == "1")
             temp += '#';
         else if(to_string(b[k] >> i & 1 ? 1 : 0) == "0")
             temp += ' ';
     }
     tmp[k] = temp;
 cout<<'\n';
 }
 cout<<'\n';
 */
