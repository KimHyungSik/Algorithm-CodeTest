#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int weight_of_bridge = 0;
    vector<int> timemer;
    queue<int> bridge;
    while (truck_weights.size() != 0) {
        answer++;
        if (weight_of_bridge + truck_weights[0]<= weight) {
            bridge.push(truck_weights[0]);
            weight_of_bridge += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
            timemer.push_back(0);    
        }
        int popCount = 0;
        for (vector<int>::size_type i = 0; i < timemer.size();i++) {
            timemer[i]++;
            if (timemer[i] == bridge_length) {
                popCount++;              
            }
        }
        for (int i = 0; i < popCount; i++) {
            weight_of_bridge -= bridge.front();
            bridge.pop();
            timemer.erase(timemer.begin());
        }
    }
   
    if (timemer.size() != 0) {
        answer += (bridge_length - timemer.back());
    }
    return answer;
}

int main() {
    vector<int> truck{ 10,10,10,10,10,10,10,10,10,10 };
    int answer = solution(100, 100, truck);
    cout << answer << endl;
}