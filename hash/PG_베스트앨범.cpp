#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

bool great(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> gp;
    unordered_map<string, vector<pair<int, int>>> um;
    for(int i = 0; i < genres.size(); i++) {
        um[genres[i]].push_back({plays[i], i});
        gp[genres[i]] += plays[i];
    }
    // map은 pair<key, value> 형태로 저장되어 있어, vector를 pair형으로 선언하고 옮겨담을 수 있다
    vector<pair<string, int>> genre_plays(gp.begin(), gp.end());
    sort(genre_plays.begin(), genre_plays.end(), great);
    for(int i = 0; i < genre_plays.size(); i++) {
        sort(um[genre_plays[i].first].begin(), um[genre_plays[i].first].end(), cmp);
        answer.push_back(um[genre_plays[i].first][0].second);
        if(um[genre_plays[i].first].size() > 1) answer.push_back(um[genre_plays[i].first][1].second);
    }
    return answer;
}
