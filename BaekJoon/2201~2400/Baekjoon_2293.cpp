#include <iostream>

using namespace std;



int main() {
    int N, M;
    int coins[101];
    int d[10001] = {0};
 
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &coins[i]);
    }
    
    d[0] = 1;
         
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j >= coins[i]) {
                d[j] += d[j-coins[i]];
            }
        }
    }
    printf("%d\n", d[M]);
    return 0;
}

