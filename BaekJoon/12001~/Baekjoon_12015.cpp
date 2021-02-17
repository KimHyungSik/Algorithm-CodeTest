// �ð� ���⵵�� O(n log n)�� ���� 
// �̺� Ž���� ����ؾ���

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

	// ù��° ���� �迭�� ����
	v.push_back(arr[0]);

	for (int i = 1; i < N; i++) {
		// ������ ������ ū ���� ��� �߰�
		if (arr[i] > v.back()) {
			v.push_back(arr[i]);
		}
		// ������ ������ �۰ų� ���� ��� ����
		else {
			int s = 0;
			int e = v.size()-1;
			int p = 0;
			// lower_bound�� ������ ��ġ�� ã��
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

	// ����� ����
	printf("%d", v.size());
	return 0;
}