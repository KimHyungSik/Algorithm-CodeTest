#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max = *max_element(priorities.begin(), priorities.end());
    while (1) {
        for (int i = 0; i < size(priorities); i++) {
            if (priorities[i] == max) {
                answer++;
                if (i == location)
                    return answer;
                priorities[i] = 0;
                max = *max_element(priorities.begin(), priorities.end());
            }
        }
    }
    return answer;
}

int main() {
    vector<int> priorites{ 1, 1, 9, 1, 1, 1 };
    int answer = solution(priorites, 0);
    cout << answer << endl;
    return 0;
}
