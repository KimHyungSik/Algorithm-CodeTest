#include <string>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> phone_numbers;
    for (auto number : phone_book) {
        phone_numbers.insert(number);
    }

    for (auto numbers : phone_book) {
        string temp = "";
        for (auto num : numbers) {
            temp += num;
            if (phone_numbers.find(temp) != phone_numbers.end() &&
                temp != numbers){
                return false;
            }
        }
    }
    return answer;
}