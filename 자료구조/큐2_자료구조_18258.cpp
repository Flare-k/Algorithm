#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Queue {
private:
    int s, e;
    int size;
    int* arr;

public:
    Queue(int n) {
        size = 0;
        s = 0;
        e = 0;
        arr = new int[n + 1];
    }

    void push(int x) {
        arr[e++] = x;
        size++;
    }

    void pop() {
        if (size == 0) cout << -1 << '\n';
        else {
            cout << arr[s] << '\n';
            s++;
            size--;
        }
    }

    void qsize() {
        cout << size << '\n';
    }

    void empty() {
        if (size == 0) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    void front() {
        if (size == 0) cout << -1 << '\n';
        else cout << arr[s] << '\n';
    }

    void back() {
        if (size == 0) cout << -1 << '\n';
        else cout << arr[e - 1] << '\n';
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int N;
    cin >> N;
    
    Queue q(N);

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (cmd == "pop") {
            q.pop();
        }
        else if (cmd == "size") {
            q.qsize();
        }
        else if (cmd == "empty") {
            q.empty();
        }
        else if (cmd == "front") {
            q.front();
        }
        else if (cmd == "back") {
            q.back();
        }
    }

    return 0;
}