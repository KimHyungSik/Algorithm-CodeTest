// 비트마스킹을 이용해서 백트래킹 방식으로 문제 해결

#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 52

using namespace std;

int n, m;
int grid[MAXN][MAXN];
int dist_grid[MAXN][MAXN];
int result = 2000000000;
bool visi[14] = { 0 };
bool bitm[1 << 13];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int MIN(int x, int y) {
	return x < y ? x : y;
}

int dis(int x, int y, int a, int b) {
	return abs(x - a) + abs(y - b);
}

int all_dist(int map[MAXN][MAXN]) {
	int sum = 0;
	for (auto h : home) {
		sum += map[h.first][h.second];
	}
	return sum;
}

void dfs(int exit, int count, int map[MAXN][MAXN]) {
	// 한번이라도 사용한 조합은 패스
	if (bitm[exit]) return;
	bitm[exit] = true;
	// 유지가능한 최대 매점 수 달성시 갱신
	if (count == m) {
		int sum = all_dist(map);
		result = result < sum ? result : sum;
		return;
	}
	for (int i = 0; i < chicken.size(); i++) {
		if (!visi[i]) {// 새로운 선택지에서 값 갱신
			int di[MAXN][MAXN];
			for (int k = 0; k < home.size(); k++) {
				di[home[k].first][home[k].second] =
					MIN(map[home[k].first][home[k].second], dis(chicken[i].first, chicken[i].second, home[k].first, home[k].second));
			}
			visi[i] = true;
			dfs(exit | (1<<i) ,count+1, di);
			visi[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> grid[x][y];
			if (grid[x][y] == 1) {
				home.push_back(make_pair(x, y));
			}
			if (grid[x][y] == 2) {
				chicken.push_back(make_pair(x, y));
			}
		}
	}
	for (int i = 0; i < chicken.size(); i++) {
		memset(dist_grid, 0, sizeof(dist_grid));
		for (int k = 0; k < home.size(); k++) {
			dist_grid[home[k].first][home[k].second] = dis(chicken[i].first, chicken[i].second, home[k].first, home[k].second);
		}
		visi[i] = true;
		dfs((1 <<i),1, dist_grid);
		visi[i] = false;
	}
	printf("%d\n", result);
	return 0;
}