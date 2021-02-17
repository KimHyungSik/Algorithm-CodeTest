// 4�и����� ��� ����� ��ǥ �� ��ġ�� ã��
// ã�� �ڸ����� ������ �־��� ũ�� ���� 
// �簢���� ��� 

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, r, c;
int n;
vector<int>v;

// ũŰ�� ��� ���̸鼭 ��Ȯ�� ��ǥ�� Ȯ��
void quadrant(int y, int x, int size) {
	int t = size / 2;
	if(!t)return;
	int tx = x, ty = y;
	if(y < t && x < t){	// 1��и�
		v.push_back(1);
	}
	if (y < t && x >= t) {	// 2��и�
		v.push_back(2);
		tx -= t;
	}
	if (y >= t && x < t) {	// 3 ��и�
		v.push_back(3);
		ty -= t;
	}
	if (y >= t && x >= t) { // 4 ��и�
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
	// ã�� ��ǥ�� Ȯ�� �ϸ鼭 ������ �湮�� �簢�� 
	// ��� �� ����
	for (int i = v.size() - 2; i >=0 ; i--) {
		result += temp * (v[i] - 1);
		temp *= 4;
	}

	printf("%d", result);
	return 0;
}
