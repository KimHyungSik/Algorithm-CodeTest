#include <iostream>
#include <deque>

using namespace std;

deque<int>v[10];
int n; 

void rot_re(int ve) {
	bool te = v[ve].front();
	v[ve].pop_front();
	v[ve].push_back(te);
}

void rot(int ve) {
	bool te = v[ve].back();
	v[ve].pop_back(); 
	v[ve].push_front(te);
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int temp;
			scanf("%1d", &temp);
			v[i+3].push_back(temp);
		}
	}
	for (int i = 0; i < 8; i++) {
		v[0].push_back(0);
		v[1].push_back(0);
		v[2].push_back(0);
		v[7].push_back(0);
		v[8].push_back(0);
		v[9].push_back(0);
	}
	
	scanf("%d", &n);

	while (n--) {
		int t, p;
		scanf("%d %d", &t, &p);
		t += 2;
		if (p > 0) {
			if (v[t - 1][2] != v[t][6]) { 
				if (v[t - 2][2] != v[t - 1][6]) { 
					if (v[t - 3][2] != v[t - 2][6]) rot_re(t - 3);
					rot(t - 2);
				}
				rot_re(t - 1); 
			}
			if (v[t + 1][6] != v[t][2]) {
				if (v[t + 2][6] != v[t + 1][2]) { 
					if (v[t + 3][6] != v[t + 2][2])rot_re(t + 3);
					rot(t + 2); 
				}
				rot_re(t + 1); 
			}
			rot(t);
		}
		else {
			if (v[t - 1][2] != v[t][6]) { 
				if (v[t - 2][2] != v[t - 1][6]) {
					if (v[t - 3][2] != v[t - 2][6]) rot(t - 3);
					rot_re(t - 2);
				}
				rot(t - 1); 
			}
			if (v[t + 1][6] != v[t][2]) { 
				if (v[t + 2][6] != v[t + 1][2]) {
					if (v[t + 3][6] != v[t + 2][2]) rot(t + 3);
					rot_re(t + 2); 
				}
				rot(t + 1); 
			}
			rot_re(t);
		}
	}

	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (v[i + 3][0] == 1)result += (1 << i);
	}
	printf("%d\n", result);
	return 0;
}