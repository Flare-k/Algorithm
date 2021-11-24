#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

ll N, init_atk, atk;
ll maxHP, curHP;

struct Dungeon {
    ll t, a, h;
};

vector<Dungeon> dgn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> init_atk;

    for (int i = 0; i < N; i++) {
        ll t, a, h;
        cin >> t >> a >> h;
        dgn.push_back({t, a, h});
    }

    ll l = 1, r = 123456000000000000LL, ans = 0;

    while (l <= r) {
        maxHP = (l + r) / 2;
        curHP = maxHP;
        atk = init_atk;

        for (int i = 0; i < dgn.size(); i++) {
            ll t = dgn[i].t;
            ll a = dgn[i].a;
            ll hp = dgn[i].h;

            if (t == 1) {
                ll cnt;

                if (h % atk == 0) cnt = hp / atk;
                else cnt = (hp / atk) + 1;
                
                curHP = curHP - a * (cnt - 1);
                
                if (curHP <= 0) break;
            }
            else {
                curHP += hp;
                if (curHP >= maxHP) curHP = maxHP;
                atk += a;
            }
        }

        if (curHP > 0) {
            ans = maxHP;
            r = maxHP - 1;
        }
        else {
            l = maxHP + 1;
        }
    }

    cout << ans;

    return 0;
}