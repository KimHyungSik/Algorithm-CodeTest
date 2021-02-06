#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    int temp;
    vector<int> map;
    vector<int> result;

    cin >> N;

    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        map.push_back(temp);
    }

    sort(map.begin(), map.end());

    cin >> M;

    for (int i = 0; i < M; i++) {
        scanf("%d", &temp);
        int s = 0;
        int e = N - 1;;
        int mid;
        bool flag = false;
        while (s <= e) {
            mid = (e + s) / 2;

            if (map[mid] == temp) {
                int count = 0;
                int pos = mid;
                flag = true;
                while (map[pos] == temp && pos < N) {//찾은 점에서 앞으로 탐색
                    count++;
                    pos++;
                }
                while (map[mid - 1] == temp && mid > 0) {//찾은 점에서 뒤로 탐색
                    count++;
                    mid--;
                }
                result.push_back(count);
                break;
            }
            if (temp > map[mid]) {
                s = mid + 1;
                continue;
            }
            if (temp < map[mid]){
                e = mid - 1;
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