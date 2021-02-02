#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	long long arrN[1000001];
	long long  arrM[1000001];
	vector<int> result;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lli", &arrN[i]);
	}

	for (int i = 0; i < M; i++) {
		scanf("%lli", &arrM[i]);
	}

	int ptr_n = 0, ptr_m = 0;
	while (ptr_n < N && ptr_m < M)
	{
		if (arrN[ptr_n] < arrM[ptr_m]) {
				printf("%lli ", arrN[ptr_n++]);
		}
		else {
			printf("%lli ", arrM[ptr_m++]);
		}
	}

	for (; ptr_n < N; ptr_n++) {
		printf("%lli ", arrN[ptr_n]);
	}
	for (; ptr_m < M; ptr_m++) {
		printf("%lli ", arrM[ptr_m]);
	}
	return 0;
}