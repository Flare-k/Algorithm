#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a; 
    cin>>a;

    queue<int> card;

    for (int i = 1; i <= a; i++) {
        card.push(i);
    }
    
    while (card.size() != 1){
        card.pop();
        card.push(card.front());
        card.pop();
    }

    cout << card.front() << '\n';
    
    return 0;
}
