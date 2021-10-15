#include <iostream>
#include <string>
using namespace std;

// 참고 : https://moondol-ai.tistory.com/423

int solution(string word) {
    string vowel = string("AEIOU");
    int size = word.size();

    for(int i = 0, b = 1; i < word.size(); i++, b *= 5) {
        size += vowel.rfind(word[i]) * 781 / b;
    }
    return size;
}

int main() {
    cout << solution("AEIOU");
    return 0;
}