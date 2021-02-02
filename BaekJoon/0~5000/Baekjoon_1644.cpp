#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <time.h>
#define MAX 4000000

using namespace std;
int sum[MAX];
bool sosu[MAX];
int main() {
    int N;
    time_t start, end;
    vector<int>arr;
    scanf("%d", &N);
    start = time(NULL);
    int sqrt_MAX = sqrt(MAX);
    for (int i = 2; i <= sqrt_MAX; i++) {
        if (!sosu[i]) {
            for (int j = i + i; j <= N; j += i) {
                sosu[j] = true;
            }
        }
    }

    for (int i = 2; i < N + 1; i++) {
        if (sosu[i] == 0) {
            arr.push_back(i);
        }
    }

    int arr_size = arr.size();
    int temp = 0;
    int result = 0;
    int p1 = 0, p2 = 1;
    temp = arr[0];

    while (p1 <= arr_size) {
        if (temp < N) {
            temp += arr[p2++];
            continue;
        }
        if (temp == N) {
            result++;
        }
        temp -= arr[p1++];
    }

    printf("%d\n", result);
    end = time(NULL);
    double delay = (double)(end - start);
    printf("%f", delay); //결과 출력
    return 0;
}