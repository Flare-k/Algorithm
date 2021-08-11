#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int from, to, value;
};

struct P {
    int idx, x, y, z;
    int dist(const P &p) {
        return min({abs(x - p.x), abs(y - p.y), abs(z - p.z)});
    }
};

vector<P> planet;
vector<Node> arr;

bool cmpx(P a, P b) {
    if (a.x < b.x) return true;
    return false;
}

bool cmpy(P a, P b) {
    if (a.y < b.y) return true;
    return false;
}

bool cmpz(P a, P b) {
    if (a.z < b.z) return true;
    return false;
}

// Node 대소 비교
bool cmp(Node& a, Node& b) {
    if (a.value < b.value) return true;
    return false;
}

const int MAX = 100001;
int d[MAX];


// union find
int getBoss(int num) {
    if (d[num] == -1) return num;

    int rst = getBoss(d[num]);
    d[num] = rst;
    return rst;
}

void setGroup(int a, int b) {
    int na = getBoss(a);
    int nb = getBoss(b);

    if (na == nb) return;
    d[nb] = na;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    planet.resize(N);

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        planet[i] = {i, x, y, z};
    }

    // 모든 케이스를 이중 포문으로 담기엔 시간초과 우려 x, y, z 각각 오름차순 정렬하여 케이스마다 저장. O(N)

    sort(planet.begin(), planet.end(), cmpx);
    for (int i = 1; i < N; i++) {
        arr.push_back({planet[i].idx, planet[i - 1].idx, planet[i - 1].dist(planet[i])});
    }

    sort(planet.begin(), planet.end(), cmpy);
    for (int i = 1; i < N; i++) {
        arr.push_back({planet[i].idx, planet[i - 1].idx, planet[i - 1].dist(planet[i])});
    }

    sort(planet.begin(), planet.end(), cmpz);
    for (int i = 1; i < N; i++) {
        arr.push_back({planet[i].idx, planet[i - 1].idx, planet[i - 1].dist(planet[i])});
    }

    fill(d, d + MAX, -1);
    sort(arr.begin(), arr.end(), cmp);

    // MST
    int cnt = 0;
    long long sum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if (getBoss(arr[i].from) != getBoss(arr[i].to)) {
            cnt++;
            sum += arr[i].value;
            setGroup(arr[i].from, arr[i].to);
            
            if (cnt == N - 1) break;
        }
    }

    cout << sum << '\n';;

    return 0;
}