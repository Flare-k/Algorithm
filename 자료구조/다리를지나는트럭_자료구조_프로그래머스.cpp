#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int max_size = 0;
    queue<int> pass;

    for (int i = 0; i < truck_weights.size(); i++) {
        while (1) {
            if (pass.empty()) {
                pass.push(truck_weights[i]);
                max_size += truck_weights[i];
                answer++;
                break;
            }
            else if (pass.size() == bridge_length) {  //도착의 경우
                max_size -= pass.front();
                pass.pop();
            }
            else {       //무게의 경우
                if (truck_weights[i] + max_size > weight) {
                    pass.push(0);
                    answer++;
                }
                else {
                    pass.push(truck_weights[i]);
                    max_size += truck_weights[i];
                    answer++;
                    break;
                }
            }
        }
    }
    
    return answer + bridge_length;
}


int main() {
    vector<int> truck_weights{7, 4, 5, 6};
    int bridge_length = 2;
    int weight = 10;
    
    cout << solution(bridge_length, weight, truck_weights) << '\n';
    
    return 0;
}
