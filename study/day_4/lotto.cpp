#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>   
#include <time.h>

int flag[46] = { 0 };

int main() {
	srand(time(NULL));

	for (int i = 0; i < 6; ) {    /// �������� ���� ���� ���� �����Ͻÿ�
		int random = rand() % 44 + 1;
		if (flag[random])
			continue;
		printf("%d \n", rand() % 44 + 1);
		flag[random] = 1;
		i++;                   //���� ���� ������ continue�� ���µ� �׶� ���ڰ�
				       //6�� �� ��� �Ҽ��ֵ��� �ϱ� ���Ͽ�
	}
}