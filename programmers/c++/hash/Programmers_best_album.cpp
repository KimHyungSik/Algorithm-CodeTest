#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int check_genres[10000] = { 0 };
    vector<string>kind;
    map<int, tuple<string, int>> genres_map;
    map<string, int> views;
    for (int i = 0; i < genres.size(); i++) {
        if (views.find(genres[i]) == views.end()){
            views.insert(make_pair(genres[i], plays[i]));
            kind.push_back(genres[i]);
        }else
            views[genres[i]] += plays[i];
        genres_map[i] = make_tuple(genres[i],plays[i]);
    }

    while (kind.size()) {
        string max_kind = kind[0];
        for (auto &kind : kind) {
            if (views[max_kind] < views[kind])
                max_kind = kind;
        }
        int two_count = 0;
        while (two_count < 2) {
            int i = -1;
            for (int t = 0; t < genres_map.size(); t++) {
                if (get<0>(genres_map[t]) == max_kind && !check_genres[t]) {
                    if (i == -1)
                        i = t;
                    else if (get<1>(genres_map[i]) < get<1>(genres_map[t]))
                        i = t;      
                }
            }
            if (i != -1) {
                answer.push_back(i);
                check_genres[i] = 1;
                two_count++;
            }else {
                break;
            }
           
        }
        for (int i = 0; i < kind.size(); i++) {
            if (kind[i] == max_kind) {
                kind.erase(kind.begin() + i);
                break;
            }
        }
    }

    return answer;
}
