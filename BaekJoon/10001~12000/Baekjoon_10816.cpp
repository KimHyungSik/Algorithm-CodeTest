#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> list;

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int s, int e){
  int p;

  p = list[(e+s)/2];

  while(s <= e){
    while(s<=e && list[s]<p) s++;
    while(s<=e && list[e]>p) e--;
    if(s <= e) {
      swap(list[s], list[e]);
      s++;
      e--;
    };
  }
  return s;
}

void quick_sort(int s, int e){
  if(s < e){
    int q = partition(s, e);
    if(s < q-1){
      quick_sort(s, q-1);
    } 
    if(q < e){
      quick_sort(q, e);
    }
  }
} 

int main() {
    //입력 속도 증가
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
    int N, M;
    int temp;
    vector<int> result;
    //맵으로 검색 기능 활성화
    map<int, int> result_map;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin>>temp;
        list.push_back(temp);
        if(result_map.find(temp) == result_map.end()){
          result_map.insert(make_pair(temp,1));
        }else{
          result_map[temp] = result_map[temp] + 1;
        }
    }

    quick_sort(0, list.size()-1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin>>temp;
        int s = 0;
        int e = N - 1;;
        int mid;
        int lower = 0, upper = N-1;
        bool flag = false;
        while (s <= e) {
            mid = (e + s) / 2;

            if (list[mid] == temp) {
                int count = 0;
                int pos = mid;
                flag = true;
                //이분 탐색으로 찾은 값 
                result.push_back(result_map[temp]);
                break;
            }
            if (temp > list[mid]) {
                s = mid + 1;
                lower = mid;
                continue;
            }
            if (temp < list[mid]){
                e = mid - 1;
                upper = mid;
                continue;
            }
        }
        if (!flag)
            result.push_back(0);

    }

    for (int x : result) {
        printf("%d ", x);
    }

    return 0;

}
