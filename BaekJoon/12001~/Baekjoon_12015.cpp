// 시간 복잡도가 O(n log n)인 문제 
// 이분 탐색을 사용해야함

#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000001];
vector<int> v;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	// 첫번째 수를 배열에 넣음
	v.push_back(arr[0]);

	for (int i = 1; i < N; i++) {
		// 마지막 수보다 큰 수일 경우 추가
		if (arr[i] > v.back()) {
			v.push_back(arr[i]);
		}
		// 마지막 수보다 작거나 같은 경우 갱신
		else {
			int s = 0;
			int e = v.size()-1;
			int p = 0;
			// lower_bound로 갱신할 위치를 찾음
			while (s <= e) {
				int mid = (s + e) / 2;
				if (v[mid] >= arr[i]) {
					p = mid;
					e = mid -1;
				}
				else {
					s = mid+1;
				}
			}
				v[p] = arr[i];
		}
	}

	// 가장긴 순열
	printf("%d", v.size());
	return 0;
}