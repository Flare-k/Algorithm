#include <iostream>
using namespace std;

int N, K;
enum {
    GIRLS, BOYS
};
struct Node {
    int girl, boy;
};
Node students[7];
int sum;

void run(int student) {
    if (student <= K) sum += 1;
    else {
        if (student % K == 0) sum += (student / K);
        else sum += (student / K + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    while (N--) {
        int S, Y;   // 성별, 학년
        
        cin >> S >> Y;

        if (S == GIRLS) students[Y].girl++;
        else if (S == BOYS) students[Y].boy++;
    }

    for (int i = 1; i <= 6; i++) {
        int girls = students[i].girl;
        int boys = students[i].boy;

        if (girls != 0) run(girls);
        if (boys != 0) run(boys);
    }

    cout << sum;

    return 0;
}