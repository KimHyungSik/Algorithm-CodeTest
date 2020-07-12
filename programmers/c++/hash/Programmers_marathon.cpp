#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> player;
    for (auto comple : completion) {
        if (player.find(comple) == player.end())
            player.insert(make_pair(comple, 1));
        else
            player[comple]++;
    }
    for (auto participant : participant) {
        if (player.find(participant) == player.end())
            return participant;
        else {
            player[participant]--;
            if (player[participant] < 0) {
                return participant;
            }
        }
    }
}