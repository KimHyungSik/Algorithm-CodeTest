// 완전한 파인드-유니온 알고리즘 문제

#include <iostream>
#define MAX 1000001

using namespace std;

int parents[MAX];
int n, m;

int find_parents(int x) {
	if (x == parents[x])return x;
	parents[x] = find_parents(parents[x]);
	return parents[x];
}

void union_(int x, int y) {
	int X = find_parents(x);
	int Y = find_parents(y);
	if (X < Y) {
		parents[Y] = X;
	}
	else {
		parents[X] = Y;
	}
}


int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)parents[i] = i;

	for (int i = 0; i < m; i++) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if (op) {
			if (find_parents(a) == find_parents(b)) printf("YES\n");
			else printf("NO\n");
		}
		else {
			union_(a, b);
		}
	}
	//for (int i = 0; i <= n; i++)printf("%d ", parents[i]);
	return 0;
}