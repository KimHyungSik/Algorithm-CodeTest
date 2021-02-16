// ���ڵ��� �ڸ����� ��� �Ͽ� ��� Ƚ���� ���
// ���� ���ڵ� �� ���� ū �� ���� 9 ~ 9-N
// ���� ����

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N;
char word[10][9];		// ����
int word_count[27];		// ���ں� ��뷮
int word_num[27];		// ���ں� ���� ����
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", word[i]);
		int size = strlen(word[i]);
		for (int j = 0; j < strlen(word[i]); j++) {
			// �ڸ����� ���� ��뷮 ����
			word_count[word[i][j] - 'A'] += pow(10, size--);
		}
	}
	int num = 9;
	// ��뷮 ���� ���� ����
	for (int i = 0; i < 27; i++) {
		int p = 0;
		for (int j = 0; j < 27; j++) {
			p = word_count[p] > word_count[j] ? p : j;
		}
		word_num[p] = num--;
		word_count[p] = 0;
	}

	int sum;
	int result = 0;
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < strlen(word[i]); j++) {
			sum *= 10;
			sum += word_num[word[i][j] - 'A'];
		}
		result += sum;
	}
	printf("%d", result);
	return 0;
}