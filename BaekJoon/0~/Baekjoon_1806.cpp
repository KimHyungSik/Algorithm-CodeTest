#include <iostream>
#include <cstring>


int main() {
	int N, M;
	int temp;
	int arr[100001];
	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &N, &M);
	long long s = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[i] = temp;
	}
	int result = 0;
	int start = 0,end = 1;
	s = arr[0];
	while (start < N) {
		if (s < M && end < N) {
			s += arr[end++];
			continue;
		}
		if (s >= M) {
			int re = (end - start);
			if (!result) {
				result = re;
;			}
			result = result < re ? result : re;
		}
		s -= arr[start++];
	}

	printf("%d", result);
	return 0;
}