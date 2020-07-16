#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for (int i = 0; i < heights.size(); i++) {
        for(int j = i; j >= 0; j--) {
            if (heights[i] < heights[j]){
                answer.push_back(j+1);
                break;
            }
            if (j == 0)
                answer.push_back(0);
        }
    }
    return answer;
}

int main() {
    vector<int> heights{ 2, 1, 1 };
    vector<int> answer = solution(heights);
    for (auto ans : answer) {
        cout << ans <<" ";
    } 
    cout << endl;
}