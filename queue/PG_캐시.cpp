#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache; // 캐시
    map<string, int> m; // 캐시 존재 여부 체크
    for(int i =0; i < cities.size(); i++) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::toupper);
        if(m[city] == 1) { // 캐시에 데이터가 있는 경우
            for(int j = 0; j < cacheSize; j++) {
                if(cache[j] == city) { // hit 시 저장된 캐시의 위치를 맨 뒤로 옮기는 방식으로 LRU 구현
                    cache.erase(cache.begin()+j);
                    cache.push_back(city);
                    answer += 1;
                    break;
                }
            }                
        } else { // 캐시에 데이터가 없는 경우
                if(cacheSize == 0) {
                    answer += 5;
                }
                else if(cache.size() < cacheSize) {
                    answer += 5;
                    cache.push_back(city);
                    m[city] = 1;
                } else { // 캐시가 가득 차 있는 경우 가장 오래동안 사용하지 않은 데이터를 제거 후 맨 뒤에 새 데이터 
                    m[cache[0]] = 0;
                    cache.erase(cache.begin());
                    cache.push_back(city);
                    m[city] = 1;
                    answer += 5;
                }
            }
        }
    return answer;
}
