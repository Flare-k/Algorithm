#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool checkMo(vector<char> alphabet){
    int ja=0, mo=0;
    for(char password : alphabet){
        if(password == 'a' || password == 'e' || password == 'i' || password == 'o' || password == 'u')
            mo += 1;
        else
            ja += 1;
    }
    return ja>=2 && mo >= 1;
}


int main(){
    int l, c;
    cin>>l>>c;
    
    vector<char> alphabet;
    vector<int> check;
    
    char alpha;
    for(int i=0; i<c; i++){
        cin>>alpha;
        alphabet.push_back(alpha);
    }                               //c개수 만큼 알파벳을 벡터에 입력
    sort(alphabet.begin(), alphabet.end());
    
    for(int i=0; i<l; i++){
        check.push_back(1); //사용한 경우
    }
    
    for(int i=0; i<alphabet.size()-l; i++){
        check.push_back(2); //사용하지 않은 경우
    }
    
    do{
        for(int i=0; i<check.size(); i++){
            if(check[i] == 1){
                    cout<<alphabet[i]<<' ';
            }
        }
        cout<<'\n';
    }while(next_permutation(check.begin(), check.end()));
    
    
    return 0;
}
