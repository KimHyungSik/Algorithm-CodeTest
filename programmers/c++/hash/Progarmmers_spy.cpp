#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<string> clothe_;
    map<string, int>collection;
    for (auto clothe : clothes) {
        if (collection.find(clothe[1]) == collection.end()) {
            collection.insert(make_pair(clothe[1], 2));
            clothe_.push_back(clothe[1]);
        }
        else
            collection[clothe[1]]++;
    }
    for (auto coll : clothe_) {
        answer *= collection[coll];
    }
    return answer-1;
}