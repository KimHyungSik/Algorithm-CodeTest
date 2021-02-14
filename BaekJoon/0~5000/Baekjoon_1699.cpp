#include<iostream>
#include <cmath>

using namespace std;

int N;
int dp[100001];

int MIN(int x, int y) {
    return x < y ? x : y;
}

int main() {
    scanf("%d", &N);

    if (!N) {
        printf("0");
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = i;
    }

    for (int i = 2; i < sqrt(N)+1; i++) {
        for (int j = i*i; j <=N; j++) {
            dp[j] = MIN(dp[j-(i*i)]+1, dp[j]);
        }
    }

    printf("%d", dp[N]);
    return 0;
}