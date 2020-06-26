#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>   
#include <time.h>

int flag[46] = { 0 };

int main() {
	srand(time(NULL));

	for (int i = 0; i < 6; ) {    /// 증감식이 여기 없는 이유 설명하시오
		int random = rand() % 44 + 1;
		if (flag[random])
			continue;
		printf("%d \n", rand() % 44 + 1);
		flag[random] = 1;
		i++;                   //같은 수가 나오면 continue가 도는데 그때 숫자가
				       //6개 다 출력 할수있도록 하기 위하여
	}
}