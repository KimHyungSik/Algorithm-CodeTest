// queue자료구조를 이용하여 문제풀이

#include <iostream>
#include <deque>
#include <cstring>
#define MAXN 101

using namespace std;

int grid[MAXN][MAXN];
int n, k, l;
deque<pair<int, char>>v;

int headBANGBANG(int di, char b) {
	if (b == 'D') {
		di++;
		if (di == 4)di = 0;
	}
	else {
		di--;
		if (di == -1) di = 3;
	}
	return di;
}

int main() {

	memset(grid, 0, sizeof(grid));

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		grid[y][x] = 1;
	}

	cin >> l;

	while (l--) {
		int t;
		char p;
		cin >> t >> p;
		v.push_back(make_pair(t, p));
	}

	int cnt = 0;
	int dir = 0;
	int now_x = 1, now_y = 1;
	deque<pair<int, int>> s;
	s.push_back(make_pair(1, 1));

	while (true) {
		cnt++;

		switch (dir) {
			case 0:
				now_x++;
				break;
			case 1:
				now_y++;
				break;
			case 2:
				now_x--;
				break;
			case 3:
				now_y--;
				break;
		}

		// 방향 전화할 시간이면 방향을 전환
		if (!v.empty()) {
			if (cnt == v.front().first) {
				dir = headBANGBANG(dir, v.front().second);
				v.pop_front();
			}
		}


		if (!now_y || !now_x || now_y > n || now_x > n) {
			cout << cnt << '\n';
			return 0;
		}

		for (int i = 0; i < s.size();i++) {
			if (now_y == s[i].first && now_x == s[i].second) {
				cout << cnt << '\n';
				return 0;
			}
		}

		// 사과를 먹는 다면 큐에 추가만 하면서 길이를 늘린다
		s.push_back(make_pair(now_y, now_x));

		if (grid[now_y][now_x]) {
			grid[now_y][now_x] = 0;
			continue;
		}
		s.pop_front();
	}
	cout << cnt << '\n';

	return 0;
}
