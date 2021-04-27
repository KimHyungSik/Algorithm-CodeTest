#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> strMap[11];
int mapMaxIndex[11];

void comb(string str, int index, string com){
    int len = (int)com.length();
    
    if(index >= str.length()){
        if(len > 1){
            strMap[len][com]++;
            mapMaxIndex[len] = max(mapMaxIndex[len], strMap[len][com]);
        }
        return;
    }
    
    comb(str, index + 1, com + str[index]);
    comb(str, index + 1, com);

}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(string order : orders){
        sort(order.begin(), order.end());
        comb(order, 0, "");
    }
    
    for(int x : course){
        for(pair<string, int> y : strMap[x]){
            
            if(y.second > 1 && y.second == mapMaxIndex[x]){
                answer.push_back(y.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main(){
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2,3,4};
        
}
