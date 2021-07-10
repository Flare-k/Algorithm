#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> map;

int solution(int cacheSize, vector<string> cities) {

    vector<string> cacheMemory;
    int caching = 0;

    for (auto city = cities.begin(); city != cities.end(); city++) {
        transform(city->begin(), city->end(), city->begin(), ::tolower);

        bool existedCity = false;

        for (auto data = cacheMemory.begin(); data != cacheMemory.end(); data++) {
            if (*city == *data) {
                existedCity = true;
                caching += 1;
                cacheMemory.erase(data);
                cacheMemory.push_back(*city);
                break;
            }

        }
        
        if (!existedCity) {
            caching += 5;
            if (cacheSize != 0 && cacheMemory.size() >= cacheSize) {
                cacheMemory.erase(cacheMemory.begin());
            }
            if (cacheMemory.size() < cacheSize) {
                cacheMemory.push_back(*city);
            }
        }
    }

    return caching;
}

int main() {
    int result = solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"});
    cout << result << '\n';

    return 0;
}