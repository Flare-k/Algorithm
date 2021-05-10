#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> linkedList;

    for (int i = 1; i <= 10; i++) {
        linkedList.push_back(i);
    }
    
    cout << "[], at 사용 x, iter의 정수연산 X, iter++, iter-- 가능\n";
    cout << "==== 1 ~ 10 입력 ====\n";
    list<int>::iterator iter;
    for (iter = linkedList.begin(); iter != linkedList.end(); iter++) {
        cout << *iter << ' ';
    }

    linkedList.remove(3);   // 제거

    cout << "\n\n";
    cout << "==== " << 3 << " 제거 remove(k)" << " ====" <<'\n';
    for (iter = linkedList.begin(); iter != linkedList.end(); iter++) {
        cout << *iter << ' ';
    }

    iter = linkedList.begin();
    iter++;
    iter++;

    linkedList.insert(iter, 3);
    cout << "\n\n";
    cout << "==== " << 3 << " 추가 insert(iter, k)" << " ====\n";
    for (iter = linkedList.begin(); iter != linkedList.end(); iter++) {
        cout << *iter << ' ';
    }

    cout << "\n\n";
    cout << "==== sort ====\n";
    linkedList.sort();
    for (iter = linkedList.begin(); iter != linkedList.end(); iter++) {
        cout << *iter << ' ';
    }

    cout << "\n\n";
    cout << "==== greater<int>() ====\n";
    linkedList.sort(greater<int>());
    for (iter = linkedList.begin(); iter != linkedList.end(); iter++) {
        cout << *iter << ' ';
    }


    return 0;
}