#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[20];
	float point;
	struct student* link;
}STUDENT;

STUDENT* pStart = NULL, * prev = NULL, * p = NULL,* search_point = NULL;

void input_move() {
	do {
		p = (STUDENT*)malloc(sizeof(STUDENT));
		printf("영화 제목을 입력하세요(입력을 종료할려면 'exit'를 입력하세요): ");
		scanf("%s", p->name);
		if (strcmp(p->name, "exit") == 0) {
			free(p);
			p = NULL;
			break;
		}
		printf("평점을 입력하세요: ");
		scanf("%f", &(p->point));

		printf("===================================\n");

		if (pStart == NULL) {
			pStart = p;
			prev = p;
		}
		else {
			prev->link = p;
			prev = p;
			prev->link = NULL;
		}
	} while (strcmp(prev->name, "exit"));
}

void printAll() {
	prev = pStart;
	while (prev != NULL) {
		printf("\n===================================\n");
		printf("제목 : %s,  평정 : %.2f\n", prev->name, prev->point);
		printf("===================================\n");
		prev = prev->link;
	}
}

void search(char search_data[20]) {
	if (search_point != NULL) {
		if (strcmp(search_point->name, search_data) == 0) {
			printf("\n===================================\n");
			printf("제목 : %s,  평정 : %.2f\n", search_point->name, search_point->point);
			printf("===================================\n");
			return;
		}
		else {
			search_point = search_point->link;
			return search(search_data);
		}
	}
	else {
		printf("\n===================================\n");
		printf("영화를 찾을수 없습니다.\n");
		printf("===================================\n");
		return;
	}
}

int main() {
	int temp = 0, loop_X = 1;
	char search_move[20];
	while (loop_X) {
		temp = 0;
		printf("1. 영화 입력, 2. 모든 영화 정보 보기, 3. 영화 검색, 0.종료:");
		scanf("%d", &temp);
		switch (temp) {
			case 1:
				input_move();
				break;
			case 2:
				printAll();
				break;
			case 3:
				printf("검색할 영화의 이름을 입력해주세요 :");
				scanf("%s", search_move);
				search_point = pStart;
				search(search_move);
				break;
			case 0:
				loop_X = 0;
				break;
			default:
				printf("없는 명령어 입니다 다시 입력해주세요.\n");
				break;
		}	
	}
	prev = pStart;
	while (pStart != NULL) {
		prev = pStart->link;
		free(pStart);
		pStart = prev;
	}

}
