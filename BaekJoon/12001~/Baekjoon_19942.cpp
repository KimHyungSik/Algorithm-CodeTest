// 백트래킹 문제
// 비트 마스크를 활용 하여 백트래킹 조건 확인
// DFS로 문제 해결

#include <iostream>
#include <cstring>
#define MAX 16
using namespace std;

int n;
int grid[MAX][5];
int target[4];
int result = -1;
int ret_pos;
bool visit[1 << MAX];

// 현재 방문한 곳, 현재 까지 가격, 비교할 데이터
void DFS(int visited, int price,int ret[5]) {
	// 백트래킹 조건
	// 한번 사용해본 조합의 경우 무시
	if (visit[visited])return;
	
	// 문제의 조건에 맞는 경우 정답 갱신
	if (target[0] <= ret[0] && target[1] <= ret[1] && target[2] <= ret[2] && target[3] <= ret[3]) {
		// 처음 들어오거나 현재 값보다 싼경우 갱신
		if (result == -1 || result > price) {
			result = price; 
			ret_pos = visited;
		}
		// 현재 조합 방문 처리
		visit[visited] = true;
		return;
	}

	// 현재 조합 방문 처리
	visit[visited] = true;

	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;
		int temp_ret[5];
		for (int j = 0; j < 4; j++) {
			temp_ret[j] = ret[j] + grid[i][j];
		}
		DFS((visited | (1 << i)), price + grid[i][4], temp_ret);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < 4; i++)cin >> target[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		DFS((1 << i),grid[i][4] ,grid[i]);
	}

	cout << result << '\n';
	int num = 1;
	
	// 사용한 비트 결과 출력
	while (ret_pos > 0) {
		if (ret_pos & 1) cout << num << ' ';
		num++;
		ret_pos >>= 1;
	}

	return 0;
}