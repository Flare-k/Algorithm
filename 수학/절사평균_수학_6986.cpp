#include <iostream>
#include <vector>
#include <algorithm>
#define ERROR 0.00000001
using namespace std;

int N, K;
vector<double> v;

double jul() {
    double sum = 0;
    for(int i = K; i < N - K; ++i) {
        sum += v[i];
    }
    return sum / (N - K * 2);
}

double bo() {
    double sum = 0;
    sum += (v[K] * K + v[N - K - 1] * K);
    for(int i = K; i < N - K; ++i) {
        sum += v[i];
    }
    return sum / N;
}

int main() {
    cin >> N >> K;

    for(int i = 0; i < N; ++i) {
        double score;
        cin >> score;
        v.push_back(score);
    }

    sort(v.begin(), v.end());
    
    printf("%.2lf\n", jul() + ERROR);
    printf("%.2lf", bo() + ERROR);
}