// 문자들의 자리수를 고려 하여 사용 횟수를 계산
// 계산된 문자들 중 가장 큰 수 부터 9 ~ 9-N
// 까지 정의

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N;
char word[10][9];		// 문자
int word_count[27];		// 문자별 사용량
int word_num[27];		// 문자별 숫자 정의
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", word[i]);
		int size = strlen(word[i]);
		for (int j = 0; j < strlen(word[i]); j++) {
			// 자릿수에 맟춰 사용량 정리
			word_count[word[i][j] - 'A'] += pow(10, size--);
		}
	}
	int num = 9;
	// 사용량 별로 숫자 정의
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