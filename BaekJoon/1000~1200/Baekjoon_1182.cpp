#include <iostream>
#define MAX 21

int n, s;
int grid[MAX];
int result = 0;

void dfs(int start,int p, int sum) {
	if (sum == s) result++;

	for (int i = start; i < n; i++) {
		dfs(i + 1, grid[i], sum + grid[i]);
	}
}

int main() {

	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++) {
		scanf("%d", &grid[i]);
	}
	
	for (int i = 0; i < n; i++) {
		dfs(i + 1, grid[i], grid[i]);
	}

	printf("%d", result);
	return 0;
}