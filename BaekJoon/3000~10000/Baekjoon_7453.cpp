#include<iostream>
#include <vector>
#include <algorithm>

#define MAX 4001

using namespace std;

int a[MAX], b[MAX], c[MAX], d[MAX];
int n;
long long result = 0;
vector<long long>cd;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cd.push_back(c[i] + d[j]);
		}
	}

	sort(cd.begin(), cd.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ab = a[i] + b[j];
			int s = 0, e = cd.size() - 1;
			int low = 0, high = 0;

			//while (s <= e) {
			//	int mid = (s + e) / 2;
			//	if (cd[mid] > -ab) {
			//		e = mid - 1;
			//		high = mid;
			//	}
			//	else if (cd[mid] <= -ab) {
			//		if(cd[mid] == -ab)
			//			low = mid;
			//		s = mid + 1;
			//	}
			//}

			low = lower_bound(cd.begin(), cd.end(), -ab) - cd.begin();
			high = upper_bound(cd.begin(), cd.end(), -ab) - cd.begin();

			if (-ab == cd[low]) {
				result += high - low;
			}
		}
	}

	printf("%lli\n", result);
	return 0;
}