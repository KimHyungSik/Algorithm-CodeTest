// stack에 추가해야할 데이터를 잘 못 선택 해서 시간이 좀 걸렸던 문제
// index값을 넣어주면서 오큰수를 판단하면서 stack을 유지해준다

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
