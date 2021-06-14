#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

struct Node {
    ll from, to, dist;
};

vector<Node> arr;
ll vect[100001];

bool cmp(Node a, Node b) {
    if (a.dist < b.dist) return true;
    return false;
}

int getBoss(ll ch) {
    if (vect[ch] == 0) return ch;

    ll res = getBoss(vect[ch]);
    vect[ch] = res;
    return res;
}

void setGroup(ll c1, ll c2) {
    ll g1 = getBoss(c1);
    ll g2 = getBoss(c2);

    if (g1 == g2) return;
    vect[g2] = g1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int house, route;
    cin >> house >> route;

    ll from, to, dist;
    for (int i = 0; i < route; i++) {
        cin >> from >> to >> dist;
        arr.push_back({from, to, dist});
    }

    sort(arr.begin(), arr.end(), cmp);

    ll price = 0;
    ll cnt = 0;
    ll iter = route / 2;

    vector<ll> t;
    for (int i = 0; i < arr.size(); i++) {
        if (getBoss(arr[i].from) != getBoss(arr[i].to)) {
            cnt++;
            price += arr[i].dist;
            setGroup(arr[i].from, arr[i].to);

            t.push_back(arr[i].dist);
        }
    }

    cout << price - t.back();

    return 0;
}