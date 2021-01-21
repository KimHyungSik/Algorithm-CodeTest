#include <string>
#include <vector>

using namespace std;

//[1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]
//1, 2, 3, 2, 3, 1
//5 4 1 2 1 0
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i < prices.size()-1;i++){
      answer.push_back(0);
      for(int j = i+1; j < prices.size();j++){
        if(prices[i] <= prices[j]){
          answer[i]++;
        }else{
          answer[i]++;
          break;
        }
      }
      if(answer[i] == 0){
        answer[i] = 1;
      }
    }
    answer.push_back(0);

    return answer;
}

int main(void){
  vector<int> prices = {1, 2, 3, 2, 3};
  vector<int> answer = solution(prices);
  for(int i = 0; i < answer.size(); i++){
    printf("%d ", answer[i]);
  }
  return 0;
}
