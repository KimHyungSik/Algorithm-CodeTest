#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

#include "Account_Contorl.h"
#include "printer.h"

#pragma warning(disable : 4996)

typedef struct Account {
	int accountNo;
	char password[21];
	int money;
	Account* front;
	Account* back;
}Account;

Account* headNode = NULL;
Account* tailNode = NULL;
Account* tempNode = NULL;
Account* createrNode = NULL;
int G_accountNo = 1;


void Create_Account() {
	createrNode = (Account*)malloc(sizeof(Account));

	char password[21];
	while (1) {
		fprintf(stdout, "비밀번호 입력(20자 이내), 통장 계설을 종료할려면 exit를 입력 :");
		scanf("%s", password);

		if (!strcmp(password, "exit")) {
			free(createrNode);
			createrNode = NULL;
			print_loading("종료중...", 1500);
			return;
		}

		fprintf(stdout, "비밀번호 확인 : ");
		scanf("%s", createrNode->password);

		if (!strcmp(createrNode->password, password)) {
			print_loading("확인되었습니다.", 1000);
			break;
		}
		else {
			print_loading("비밀번호가 다릅니다. 다시 입력해 주세요.", 1000);
		}
	}

	createrNode->accountNo = G_accountNo++;
	createrNode->money = 0;

	if (headNode == NULL) {//통장 첫 계설 시
		headNode = createrNode;
		tempNode = createrNode;
		tailNode = createrNode;

		headNode->front = NULL;
		headNode->back = NULL;
	}
	else {
		tempNode = tailNode;
		tailNode = createrNode; //생성된 통장을 마지막 통장으로 설정

		//전에 있던 통장과 연결
		tailNode->front = tempNode;
		tempNode->back = createrNode;

		tempNode = createrNode;
		tempNode->back = NULL;
	}
	print_loading("통장 계설중...", 1500);
	fprintf(stdout, "통장이 계설 되었습니다.\n");
	fprintf(stdout, "계좌 번호는 %d 입니다.\n", createrNode->accountNo);
	Sleep(1500);
	system("cls");
}

//통장 조회시 사용
void Allquest_Account() {
	if (headNode == NULL) {//통장이 존재 하지 않을 경우
		print_loading("가지고 있는 통장이 없습니다", 600);
	}

	tempNode = headNode;
	while(tempNode != NULL) {
		fprintf(stdout, "==================\n");
		fprintf(stdout, "accountNo = %d\n", tempNode->accountNo);
		fprintf(stdout, "money = %d\n", tempNode->money);
		fprintf(stdout, "==================\n\n");

		tempNode = tempNode->back;
	}
	fprintf(stdout, "아무키나 눌러서 돌아가기\n");
	while (true) {
		if (kbhit()) {
			break;
		}
	}
	system("cls");
}

void diposit(int findNo, int money) {
	if (tempNode == NULL) return;
	findAccount(findNo);

	tempNode->money += money;

	fprintf(stdout, "계좌 번호 %d의 남은 잔액은 %d 입니다.\n", tempNode->accountNo, tempNode->money);
	Sleep(1500);
	system("cls");
}

void withdraw(int findNo, int money) {
	if (tempNode == NULL) return;
	if (!checkPassword(findNo)) return;

	if (tempNode->money < money) {
		print_loading("잔액이 부족합니다", 1200);
		return;
	}

	tempNode->money -= money;
	fprintf(stdout, "계좌 번호 %d의 남은 잔액은 %d 입니다.\n", tempNode->accountNo, tempNode->money);
	Sleep(1500);
	system("cls");
}

void sendTo(int fromNo,int toNo ,int money){
	if (tempNode == NULL) return;

	if (!checkPassword(fromNo)) return;
	//놀고 있는 통장 생성자 사용
	createrNode = tempNode;
	findAccount(toNo);

	if (createrNode->money < money) {
		print_loading("잔액이 부족합니다", 1200);
		return;
	}

	createrNode->money -= money;
	tempNode->money += money;
	fprintf(stdout, "계좌 번호 %d의 남은 잔액은 %d 입니다.\n", createrNode->accountNo, createrNode->money);
	fprintf(stdout, "계좌 번호 %d의 남은 잔액은 %d 입니다.\n", tempNode->accountNo, tempNode->money);
	Sleep(1500);
	system("cls");
}

//원하는 통장을 찾아주는 함수
int findAccount(int findNo) {
	if (headNode == NULL) {//통장이 존재 하지 않을 경우
		print_loading("가지고 있는 통장이 없습니다", 600);
	}
	tempNode = headNode;
	while (tempNode != NULL) {
		if (tempNode->accountNo == findNo) {
			return 1;
		}
		tempNode = tempNode->back;
	}
	return 0;
}

int checkPassword(int findNo) {
	findAccount(findNo);
	if (tempNode == NULL) return 0;

	char password[21];
	for (int i = 0; i < 3; i++) {
		fprintf(stdout, "비밀번호 입력 : ");
		scanf("%s", password);

		if (!strcmp(tempNode->password, password)) {
			print_loading("비밀번호 확인", 800);
			return 1;
		}
		print_loading("비밀번호를 다시 입력해 주세요", 800);
	}
	print_loading("입력이 3회 틀렸습니다", 800);
	return 0;
}

void exit() {
	tempNode = headNode;
	while (tempNode != NULL) {
		tempNode = headNode->back;
		free(headNode);
		headNode = tempNode;
	}
}

