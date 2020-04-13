#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool checkMo(string alphabet){
    int ja=0, mo=0;
    for(int i=0; i<alphabet.size(); i++){
        if(alphabet[i]=='a'||alphabet[i]=='e'||alphabet[i]=='i'||alphabet[i]=='o'||alphabet[i]=='u'){
            mo++;
        }
        else
            ja++;
    }
    return (ja >= 2 && mo >= 1) ? true:false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int l, c;   // l=선택할 개수, c=입력 개수
    cin>>l>>c;
    
    vector<char> alphabet;
    vector<int> check;
    
    char alpha;
    for(int i=0; i<c; i++){
        cin>>alpha;
        alphabet.push_back(alpha);
    }sort(alphabet.begin(), alphabet.end());     //c개수 만큼 알파벳을 벡터에 입력
    
    for(int i=0; i<l; i++){
        check.push_back(1); //사용한 경우
    }
    for(int i=0; i<alphabet.size()-l; i++){
        check.push_back(2); //사용하지 않은 경우
    }

    vector<string> answer;
    do{
        string temp="";
        for(int i=0; i<check.size(); i++){
            if(check[i] == 1)
                temp+=alphabet[i];
        }
        if(checkMo(temp)){
            answer.push_back(temp);
        }
    }while(next_permutation(check.begin(), check.end()));
    
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<'\n';
    }
    
    return 0;
}
/*
 4 6
 a t c i s w
 */
