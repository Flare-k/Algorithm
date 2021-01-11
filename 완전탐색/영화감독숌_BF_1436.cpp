#include <iostream>
#include <string>
using namespace std;

/*
"N번째로 작은 666을 가진 숫자"
1666 2666 3666 4666 5666 6660 6661 ...
수가 작은 것부터 나열하는 건데 천의 자리를 늘려서 7666을 만들면 6660보다 크니까
순서대로가 아니다.
*/

int Findseries(int N) {
    int i = 666;
    int series = 0;
    string target;

    while (1) {
        target = to_string(i);
        for (int j = 0; j < target.length() - 2; j++)
            if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6') {
                series++;  // 만약 N = 7이라고 하면 앞서 666이 나오는 개수를 모두
                        // 센다. 5666에서 series는 6이 될것이다. 무한루프로 i는
                        // 쭉 커지면 6659까지 되고 i가 6660이 되며 if문이
                        // 통과되고 series는 7로 된다. 즉, 무한루프를 돌며 666이
                        // 나올때마다 series가 증가하게 되는 구조이다.
                if (series == N) return i;
                break;  // 666을 찾는 순간 break한다.
                        // 666이 다른 곳에 중첩되어 있을 것을 대비
            }
        i++;
    }
}
int main() {
    int N;
    cin >> N;
    
    cout << Findseries(N);
}