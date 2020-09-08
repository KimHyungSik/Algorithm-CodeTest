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
		fprintf(stdout, "��й�ȣ �Է�(20�� �̳�), ���� �輳�� �����ҷ��� exit�� �Է� :");
		scanf("%s", password);

		if (!strcmp(password, "exit")) {
			free(createrNode);
			createrNode = NULL;
			print_loading("������...", 1500);
			return;
		}

		fprintf(stdout, "��й�ȣ Ȯ�� : ");
		scanf("%s", createrNode->password);

		if (!strcmp(createrNode->password, password)) {
			print_loading("Ȯ�εǾ����ϴ�.", 1000);
			break;
		}
		else {
			print_loading("��й�ȣ�� �ٸ��ϴ�. �ٽ� �Է��� �ּ���.", 1000);
		}
	}

	createrNode->accountNo = G_accountNo++;
	createrNode->money = 0;

	if (headNode == NULL) {//���� ù �輳 ��
		headNode = createrNode;
		tempNode = createrNode;
		tailNode = createrNode;

		headNode->front = NULL;
		headNode->back = NULL;
	}
	else {
		tempNode = tailNode;
		tailNode = createrNode; //������ ������ ������ �������� ����

		//���� �ִ� ����� ����
		tailNode->front = tempNode;
		tempNode->back = createrNode;

		tempNode = createrNode;
		tempNode->back = NULL;
	}
	print_loading("���� �輳��...", 1500);
	fprintf(stdout, "������ �輳 �Ǿ����ϴ�.\n");
	fprintf(stdout, "���� ��ȣ�� %d �Դϴ�.\n", createrNode->accountNo);
	Sleep(1500);
	system("cls");
}

//���� ��ȸ�� ���
void Allquest_Account() {
	if (headNode == NULL) {//������ ���� ���� ���� ���
		print_loading("������ �ִ� ������ �����ϴ�", 600);
	}

	tempNode = headNode;
	while(tempNode != NULL) {
		fprintf(stdout, "==================\n");
		fprintf(stdout, "accountNo = %d\n", tempNode->accountNo);
		fprintf(stdout, "money = %d\n", tempNode->money);
		fprintf(stdout, "==================\n\n");

		tempNode = tempNode->back;
	}
	fprintf(stdout, "�ƹ�Ű�� ������ ���ư���\n");
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

	fprintf(stdout, "���� ��ȣ %d�� ���� �ܾ��� %d �Դϴ�.\n", tempNode->accountNo, tempNode->money);
	Sleep(1500);
	system("cls");
}

void withdraw(int findNo, int money) {
	if (tempNode == NULL) return;
	if (!checkPassword(findNo)) return;

	if (tempNode->money < money) {
		print_loading("�ܾ��� �����մϴ�", 1200);
		return;
	}

	tempNode->money -= money;
	fprintf(stdout, "���� ��ȣ %d�� ���� �ܾ��� %d �Դϴ�.\n", tempNode->accountNo, tempNode->money);
	Sleep(1500);
	system("cls");
}

void sendTo(int fromNo,int toNo ,int money){
	if (tempNode == NULL) return;

	if (!checkPassword(fromNo)) return;
	//��� �ִ� ���� ������ ���
	createrNode = tempNode;
	findAccount(toNo);

	if (createrNode->money < money) {
		print_loading("�ܾ��� �����մϴ�", 1200);
		return;
	}

	createrNode->money -= money;
	tempNode->money += money;
	fprintf(stdout, "���� ��ȣ %d�� ���� �ܾ��� %d �Դϴ�.\n", createrNode->accountNo, createrNode->money);
	fprintf(stdout, "���� ��ȣ %d�� ���� �ܾ��� %d �Դϴ�.\n", tempNode->accountNo, tempNode->money);
	Sleep(1500);
	system("cls");
}

//���ϴ� ������ ã���ִ� �Լ�
int findAccount(int findNo) {
	if (headNode == NULL) {//������ ���� ���� ���� ���
		print_loading("������ �ִ� ������ �����ϴ�", 600);
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
		fprintf(stdout, "��й�ȣ �Է� : ");
		scanf("%s", password);

		if (!strcmp(tempNode->password, password)) {
			print_loading("��й�ȣ Ȯ��", 800);
			return 1;
		}
		print_loading("��й�ȣ�� �ٽ� �Է��� �ּ���", 800);
	}
	print_loading("�Է��� 3ȸ Ʋ�Ƚ��ϴ�", 800);
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

