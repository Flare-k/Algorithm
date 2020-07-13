#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 100000+1;
bool visit[MAX];

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
    int answer = 0;
    
    for(int i=0; i<langs.size(); i++){
        if(langs[i] == "C" || langs[i] == "C++" || langs[i] == "C#")
            langs[i] = "C";
    }
    
    
    for(int i=0; i<ip_addrs.size()-2; i++){
        int cntIP = 1;
        int cntLan = 1;
        int cntSco = 1;
        if(!visit[i]){
            visit[i] = true;
            for(int j=i+1; j<ip_addrs.size(); j++){
                if(ip_addrs[i] == ip_addrs[j] && !visit[j]){
                    visit[j] = true;
                    cntIP += 1;
                }
                if(cntIP == 2){
                        if(langs[i] == langs[j]){
                            cntLan += 1;
                            if(cntLan == 2){
                                if(scores[i] == scores[j]){
                                    cntSco += 1;
                                    if(cntSco == 2)
                                        answer += 1;
                                }
                            }
                        }
                    }
                    else if(cntIP == 3){
                        if(langs[i] == langs[j]){
                            cntLan += 1;
                            if(cntLan == 3)
                                answer += 1;
                        }
                    }
                    else if(cntIP == 4)
                        answer += 1;
                }
        }
    }
    return answer;
}

int main() {
    vector<string> ip={"5.5.5.5", "155.123.124.111", "10.16.125.0", "155.123.124.111", "5.5.5.5", "155.123.124.111", "10.16.125.0", "10.16.125.0"};
    vector<string> langs={"Java", "C++", "Python3", "C#", "Java", "C", "Python3", "JavaScript"};
    vector<int> score={294, 197, 373, 45, 294, 62, 373, 373};
    cout<<solution(ip, langs, score)<<'\n';
    return 0;
}
