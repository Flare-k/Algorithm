#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#define endl "\n"
using namespace std;

class Deque{
private:
    int deque[10000];
    int length = 0;
public:
    void push_front(int n) {
        if(empty())
            deque[0] = n;
        else{
            for (int i = length; i > 0; i--) {
                deque[i] = deque[i - 1];
            }
            deque[0] = n;
        }
        length++;
    }
    
    void push_back(int n) {
        deque[length] = n;
        length++;
    }
    
    void pop_front() {
        if (!empty()) {
            cout << deque[0] << endl;
            for (int i = 0; i < length - 1; i++)
                deque[i] = deque[i + 1];
            length--;
        }
        else{
            cout << -1 << endl;
        }
    }
    
    void pop_back(){
        if(!empty()){
            cout << deque[length - 1] << endl;
            length--;
        }
        else{
            cout << -1 << endl;
        }
    }

    void size() {
        cout << length << endl;
    }

    bool empty() {
        if (length == 0)
            return true;

        return false;
    }

    void front() {
        if (!empty())
            cout << deque[0] << endl;
        else
            cout << -1 << endl;
    }

    void back() {
        if (!empty())
            cout << deque[length - 1] << endl;
        else
            cout << -1 << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Deque queue;

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "push_front") {
            int num;
            cin >> num;
            queue.push_front(num);
        }
        else if (cmd == "push_back") {
            int num;
            cin >> num;
            queue.push_back(num);
        }
        else if (cmd == "pop_front") {
            queue.pop_front();
        }
        else if (cmd == "pop_back") {
            queue.pop_back();
        }
        else if (cmd == "size") {
            queue.size();
        }
        else if (cmd == "front") {
            queue.front();
        }
        else if (cmd == "back") {
            queue.back();
        }
        else if (cmd == "empty") {
            if (queue.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    
    return 0;
}
