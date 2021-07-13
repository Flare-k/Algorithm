#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

/* 다른 사람의 풀이 참고 */

// 최소성 확인
bool possi(vector<int> vec,int now){
    for(int i = 0; i < vec.size(); i++)
        // ans에 있던 조합이 이번에 들어온 조합이랑 같은 것인지 확인
        if((vec[i] & now) == vec[i])
            return false;

    return true;
}

int solution(vector<vector<string>> relation) {
    int rowSize = (int)relation.size(); 
    int colSize = (int)relation[0].size();
    vector<int> ans;

    // 조합 경우의 수
    /*
     1(0001) - 학번
     2(0010) - 이름
     3(0011) - 이름, 학번
     4(0100) - 전공
     5(0101) - 학번, 전공
     6(0110) - 이름, 전공
     7(0111) - 학번, 이름, 전공
     8(1000) - 학년
     9(1001) - 학번, 학년
     10(1010) - 이름, 학년
     11(1011) - 학번, 이름, 학년
     12(1100) - 전공, 학년
     13(1101) - 학번, 전공, 학년
     14(1110) - 이름, 전공, 학년
     15(1111) - 학번, 이름, 전공, 학년
     */
    for(int i = 1; i < (1<<colSize); i++){
        set<string> s; //

        for(int j = 0; j < rowSize; j++){
            string now = "";

            for(int k = 0; k < colSize; k++){
                  // 선택된 컬럼과 일치한다면
                if(i & (1<<k))
                    now += relation[j][k];
            }
            s.insert(now);
        }

        // s.size() == rowSize => 중복체크
        if(s.size() == rowSize && possi(ans,i))
            ans.push_back(i);
    }

    return (int)ans.size();
}

int main() {
   int ans = solution({{"100", "ryan", "music", "2"},
                       {"200", "apeach", "math", "2"},
                       {"300", "tube", "computer", "3"},
                       {"400", "con", "computer", "4"},
                       {"500", "muzi", "music", "3"},
                       {"600", "apeach", "music", "2"}});

   cout << ans;

   return 0;
}