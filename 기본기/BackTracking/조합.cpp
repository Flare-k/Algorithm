#include <iostream>
using namespace std;

char vect[5] = "ABTQ";
int used[100];
char path[10];

void run(int level, int start) {
    if (level == 3) {
        cout << path << '\n';
        return;
    }

    for (int i = start; i < 4; i++) {
        if (used[vect[i]] == 1) continue;
        
        char ch = vect[i];

        used[ch] = 1;
        path[level] = ch;
        run(level + 1, i + 1);
        path[level] = 0;
        used[ch] = 0;
    }
}

int main() {
    run(0, 0);

    return 0;
}