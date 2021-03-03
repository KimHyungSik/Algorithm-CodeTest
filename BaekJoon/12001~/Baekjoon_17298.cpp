// stack�� �߰��ؾ��� �����͸� �� �� ���� �ؼ� �ð��� �� �ɷȴ� ����
// index���� �־��ָ鼭 ��ū���� �Ǵ��ϸ鼭 stack�� �������ش�

#include <iostream>
#include <stack>
#define MAXN 1000001

using namespace std;

int n;
int arr[MAXN];
int result[MAXN];
stack<int>st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		while (!st.empty() && arr[st.top()] < arr[i]) {
			result[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (!result[i])cout << "-1 ";
		else cout << result[i] << ' ';
	}

	return 0;
}
