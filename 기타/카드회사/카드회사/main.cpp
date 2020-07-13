#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(const string& s1, const string& s2){
    if(s1 > s2)
        return false;
    return true;
}

string solution(vector<string> registered_list, string new_id) {
    string answer = "";
    int cnt=0;
    for(int i=0; i<registered_list.size(); i++){
        if(registered_list[i] != new_id)
            cnt++;
    }
    
    if(cnt == registered_list.size())
        return new_id;
    else{
        vector<int> sn;
        for(int i=0; i<registered_list.size(); i++){
             string n;
            for(int j=0; j<registered_list[i].size(); j++){
                if(isdigit(registered_list[i][j]))
                    n += registered_list[i][j];
                else continue;
            }
            if(n!="")
                sn.push_back(stoi(n));
            else
                sn.push_back(stoi("0"));
        }
       sort(sn.begin(), sn.end());
        
        string a = "";
        string ne = "";
        for(int i=0; i<new_id.size(); i++){
            if(isdigit(new_id[i])){
                a += new_id[i];
            }
            else
                ne += new_id[i];
        }
        if(a=="")
            a += "0";
       
        int idx = 0;
        while(to_string(sn[idx]) == a){
            int tem=0;
            tem = stoi(a);
            a = to_string(tem+1);
            idx++;
        }
        answer = ne+a;
        
    }
    return answer;
}


int main(){
    vector<string> regis = {"apple1", "orange", "banana3"};
    string new_id = "apple";
    cout<<solution(regis, new_id)<<'\n';
    return 0;
}
/*

 문제 설명

 A카드사 홈페이지에 가입된 아이디들은 다음과 같은 형태를 갖추고 있습니다.

     모든 아이디는 S+N 형식입니다.
         S는 알파벳 소문자(a ~ z)로 구성된 문자열로 길이는 3 이상 6 이하입니다.
         N는 숫자(0~9)로 구성된 문자열로 길이는 0 이상 6 이하입니다.
             N의 길이가 0이 될 수도 있다는 것은, N이 비어있는 널(null) 문자열이 될 수도 있다는 의미입니다.
             N의 길이가 1 이상이면, N의 첫자리는 "0"이 될 수 없습니다.
             즉, "034" , "06", "0", "09040", "000"과 같은 문자열은 N이 될 수 없습니다.

 위의 규칙에 부합하는, 올바른 아이디의 예를 들어보면 다음과 같습니다.
 "ace", "hahaa512", "sunfri1", "aaaaaa900000", "abcde10101"

 위의 규칙에 위배되는, 잘못된 아이디의 예를 들어보면 다음과 같습니다.
 아이디     부적합 사유
 "ac"     S의 길이가 3 미만입니다.
 "Ange1004"     S에 알파벳 소문자가 아닌 문자가 포함되어 있습니다.
 "1004angel"     S+N 형식이 아닙니다.(N+S형식은 허용하지 않습니다.)
 "aaaaa1aaaaa"     S+N 형식이 아닙니다.(S+N+S 형식은 허용하지 않습니다.)
 "triger0145"     N의 첫자리가 "0"이 될 수 없습니다.
 "abcdefg733"     S의 길이가 6을 초과합니다.
 "zzzzz4954951"     N의 길이가 6을 초과합니다.

 이미 홈페이지에 가입된 아이디들의 목록(registered_list)과, 신규회원이 사용하기를 원하는 아이디(new_id)가 있다면, 아래와 같은 방법으로 신규회원에게 아이디를 추천해주려고 합니다.

     new_id가 registered_list에 포함되어 있지 않다면, new_id를 추천하고 종료합니다.

     new_id가 registered_list에 포함되어 있다면,

     2-1. new_id를 두 개의 문자열 S와 N으로 분리합니다.
     2-2. 문자열 N을 10진수 숫자로 변환한 값을 n이라고 합니다.(단, N이 비어있는 null 문자열이라면, n은 0이 됩니다.)
     2-3. n에 1을 더한 값(n+1)을 문자열로 변환한 값을 N1라고 합니다.
     2-4. new_id를 S+N1로 변경하고 1.로 돌아갑니다.

 이미 가입된 아이디들의 목록 registered_list와 신규회원이 사용하기를 원하는 아이디 new_id가 매개변수로 주어집니다. 이때 설명한 방법을 적용했을 때, 신규회원에게 추천되는 아이디를 return 하도록 solution 함수를 완성해주세요.
 제한사항

     new_id는 올바른 S+N 형식의 아이디(문자열)입니다.
     registered_list는 길이가 1 이상 100,000 이하인 문자열 배열입니다.
         registered_list의 각 원소는 올바른 S+N 형식의 아이디(문자열)입니다.
         registered_list에 중복된 원소는 없습니다.(즉, 모두 서로 다른 아이디입니다.)
     문제에서 설명된 방법을 적용하여 return 되는 추천 아이디는 항상 올바른 S+N 형식임이 보장됩니다.
         즉, 추천 아이디를 결정하는 방법을 수행하면서 N 부분의 자릿수가 6을 초과하는 경우의 입력은 주어지지 않습니다.

 입출력 예
 registered_list     new_id     result
 ["card", "ace13", "ace16", "banker", "ace17", "ace14"]     "ace15"     "ace15"
 ["cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5"]     "cow"     "cow10"
 ["bird99", "bird98", "bird101", "gotoxy"]     "bird98"     "bird100"
 ["apple1", "orange", "banana3"]     "apple"     "apple"
 입출력 예 설명

 입출력 예 #1
 registered_list에 new_id("ace15")가 포함되지 않았으므로, "ace15"가 추천 아이디입니다.

 입출력 예 #2
 registered_list에 new_id("cow")가 포함되어 있으므로, 다음과 같이 new_id를 바꾸는 과정을 거칩니다.
 "cow" ⇒ "cow1" ⇒ "cow2" ⇒ "cow3" ⇒ "cow4" ⇒ "cow5" ⇒ "cow6" ⇒ "cow7" ⇒ "cow8" ⇒ "cow9" ⇒ "cow10"
 "cow10"은 registered_list에 포함되지 않았으므로, "cow10"가 추천 아이디입니다.

 입출력 예 #3
 registered_list에 new_id("bird98")가 포함되어 있으므로, 다음과 같이 new_id를 바꾸는 과정을 거칩니다.
 "bird98" ⇒ "bird99" ⇒ "bird100"
 "bird100"은 registered_list에 포함되지 않았으므로, "bird100"가 추천 아이디입니다.

 입출력 예 #4
 registered_list에 new_id("apple")가 포함되지 않았으므로, "apple"가 추천 아이디입니다.

 */
