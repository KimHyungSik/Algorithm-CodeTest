#include <stdio.h>
#include <Windows.h>

#include "Account_Contorl.h"
#include "printer.h"

void Proc_info() {
	print_loading("�� ���α׷��� [����������α׷�]�Դϴ�. �Ա� / ��� / �ܾ���ȸ ����", 1500);
}


int Menu_show() {
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "    ATM(�������)���α׷�-���θ޴�\n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "1. �Ա��ϱ� \n");
	fprintf(stdout, "2. ����ϱ� \n");
	fprintf(stdout, "3. �ܾ���ȸ�ϱ� \n");
	fprintf(stdout, "4. ���� �輳 \n");
	fprintf(stdout, "5. ���� ��ü \n");
	fprintf(stdout, "6. ���� \n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "���ϴ� ��ȣ�� �Է��ϼ��� : ");
	int number;
	scanf_s("%d", &number);
	return number;
}

void MainLoop() {
	while (1) {
		switch (Menu_show()) {
		case 1:
			print_loading("�Ա� �غ���...", 1000);
			dispositMoney();
			break;
		case 2:
			print_loading("��� �غ���...", 1000);
			withdrawMoney();
			break;
		case 3:
			print_loading("�ܾ� ��ȸ��...", 1500);
			Allquest_Account();
			break;
		case 4:
			print_loading("���� �輳 �غ���...", 800);
			Create_Account();
			break;
		case 5:
			print_loading("��ü �غ���...", 800);
			sendToMoney();
			break;
		case 6:
			print_loading("������...", 1500);
			exit();
			return;
			break;
		default:
			print_loading("Error...", 1300);
			break;
		}
	}
}

void dispositMoney() {
	fprintf(stdout, "�Ա��� ���� ��ȣ�� �Է����ּ��� : ");
	int No, money;
	scanf_s("%d", &No);
	if (!findAccount(No)) {
		print_loading("�������� �ʴ� ���� ��ȣ �Դϴ�", 1000);
		return;
	}
	fprintf(stdout, "�Ա��� �ݾ��� �Է����ּ��� : ");
	scanf_s("%d", &money);
	diposit(No, money);
}

void withdrawMoney() {
	fprintf(stdout, "�Ա��� ���� ��ȣ�� �Է����ּ��� : ");
	int No, money;
	scanf_s("%d", &No);
	if (!findAccount(No)) {
		print_loading("�������� �ʴ� ���� ��ȣ �Դϴ�", 1000);
		return;
	}
	fprintf(stdout, "����� �ݾ��� �Է����ּ��� : ");
	scanf_s("%d", &money);
	withdraw(No, money);
}

void sendToMoney() {
	fprintf(stdout, "����� ���� ��ȣ�� �Է����ּ��� : ");
	int fromNo, toNo, money;

	scanf_s("%d", &fromNo);
	if (!findAccount(fromNo)) {
		print_loading("�������� �ʴ� ���� ��ȣ �Դϴ�", 1000);
		return;
	}

	fprintf(stdout, "��ü�� ���� ��ȣ�� �Է����ּ��� : ");
	scanf_s("%d", &toNo);
	if (!findAccount(toNo)) {
		print_loading("�������� �ʴ� ���� ��ȣ �Դϴ�", 1000);
		return;
	}

	fprintf(stdout, "����� �ݾ��� �Է����ּ��� : ");
	scanf_s("%d", &money);

	sendTo(fromNo, toNo, money);
}

void print_loading(const char* mas, int delay) {
	system("cls");
	fprintf(stdout, "%s\n", mas);
	Sleep(delay);
	system("cls");
}