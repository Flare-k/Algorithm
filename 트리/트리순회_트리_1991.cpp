#include <iostream>
#include <algorithm>
using namespace std;

int tree[27][2];

void preorder(int parent) {  // 전위순회
    if (parent == -1) return;
    cout << (char)(parent + 'A');
    preorder(tree[parent][0]);
    preorder(tree[parent][1]);
}

void inorder(int parent) {  // 중위 순회
    if (parent == -1) return;
    inorder(tree[parent][0]);
    cout << (char)(parent + 'A');
    inorder(tree[parent][1]);
}

void postorder(int parent) {  // 후위 순회
    if (parent == -1) return;
    postorder(tree[parent][0]);
    postorder(tree[parent][1]);
    cout << (char)(parent + 'A');
}


int main() {
    int n;
    char node, leftChild, rightChild;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> node >> leftChild >> rightChild;
        node -= 'A';
        if (leftChild == '.') {
            tree[node][0] = -1;
        } else {
            tree[node][0] = leftChild - 'A';
        }

        if (rightChild == '.') {
            tree[node][1] = -1;
        } else {
            tree[node][1] = rightChild - 'A';
        }
    }
    
    preorder(0);
    cout << '\n';

    inorder(0);
    cout << '\n';

    postorder(0);
    cout << '\n';
}
