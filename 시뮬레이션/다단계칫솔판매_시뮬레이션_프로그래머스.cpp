#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int vect[10001];
int totalEnroll[10001];
map<string, int> m;

int getBoss(int num, int price) {
    if (vect[num] == 0 && price <= 0) return num;

    int res;

    if (price >= 10) {
        totalEnroll[num] += (price - int(price * 0.1));
        res = getBoss(vect[num], int(price * 0.1));
    }
    else {
        totalEnroll[num] += price;
        res = getBoss(vect[num], 0);
    }

    return res;
}

void setGroup(int n1, int n2) {
    if (n1 == n2) return;
    vect[n2] = n1;
}

// enroll : 자식, referral : 부모
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    int idx = 0;
    m["-"] = idx++;

    for (string p : enroll) {
        m[p] = idx++;
    }

    fill(totalEnroll, totalEnroll + 1000, 0);   // totalEnroll 초기화

    // 같은 그룹이 아니라면 부모-자식 관계 갱신
    for (int i = 0; i < enroll.size(); i++) {
        if (getBoss(m[enroll[i]], 0) != getBoss(m[referral[i]], 0)) {
            setGroup(m[referral[i]], m[enroll[i]]);   
        }
    }

    idx = 0;
    while (idx != seller.size()) {
        getBoss(m[seller[idx]], amount[idx] * 100);
        idx++;
    }   // 현재 위치에서 재귀적으로 부모를 탐색하며 계산

    vector<int> answer;

    for (int i = 1; i <= enroll.size(); i++) {
        answer.push_back(totalEnroll[i]);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> result = solution(
        {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"},
        {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"},
        {"young", "john", "tod", "emily", "mary"}, 
        {12, 4, 2, 5, 10});

    for (int ans : result) {
        cout << ans << ' ';
    }

    return 0;
}