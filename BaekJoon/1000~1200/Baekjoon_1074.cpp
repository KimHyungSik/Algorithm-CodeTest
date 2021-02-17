// 4분면으로 계속 나누어서 목표 값 위치를 찾음
// 찾은 자릿수로 이전에 있었던 크고 작은 
// 사각형을 계산 

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, r, c;
int n;
vector<int>v;

// 크키를 계속 줄이면서 정확한 좌표를 확인
void quadrant(int y, int x, int size) {
	int t = size / 2;
	if(!t)return;
	int tx = x, ty = y;
	if(y < t && x < t){	// 1사분면
		v.push_back(1);
	}
	if (y < t && x >= t) {	// 2사분면
		v.push_back(2);
		tx -= t;
	}
	if (y >= t && x < t) {	// 3 사분면
		v.push_back(3);
		ty -= t;
	}
	if (y >= t && x >= t) { // 4 사분면
		v.push_back(4);
		tx -= t;
		ty -= t;
	}
	quadrant(ty, tx, t);
}

int main() {
	scanf("%d %d %d", &N, &r, &c);
	
	n = (int)pow(2, N);
	
	quadrant(r, c, n);

	int result = v.back() - 1;

	int temp = 4;
	// 찾은 좌표를 확인 하면서 이전에 방문한 사각형 
	// 계산 후 갱신
	for (int i = v.size() - 2; i >=0 ; i--) {
		result += temp * (v[i] - 1);
		temp *= 4;
	}

	printf("%d", result);
	return 0;
}
