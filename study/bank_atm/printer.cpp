#include <stdio.h>
#include <Windows.h>

#include "Account_Contorl.h"
#include "printer.h"

void Proc_info() {
	print_loading("이 프로그램은 [은행관리프로그램]입니다. 입금 / 출금 / 잔액조회 가능", 1500);
}


int Menu_show() {
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "    ATM(은행관리)프로그램-메인메뉴\n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "1. 입금하기 \n");
	fprintf(stdout, "2. 출금하기 \n");
	fprintf(stdout, "3. 잔액조회하기 \n");
	fprintf(stdout, "4. 통장 계설 \n");
	fprintf(stdout, "5. 계좌 이체 \n");
	fprintf(stdout, "6. 종료 \n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "원하는 번호를 입력하세요 : ");
	int number;
	scanf_s("%d", &number);
	return number;
}

void MainLoop() {
	while (1) {
		switch (Menu_show()) {
		case 1:
			print_loading("입금 준비중...", 1000);
			dispositMoney();
			break;
		case 2:
			print_loading("출금 준비중...", 1000);
			withdrawMoney();
			break;
		case 3:
			print_loading("잔액 조회중...", 1500);
			Allquest_Account();
			break;
		case 4:
			print_loading("통장 계설 준비중...", 800);
			Create_Account();
			break;
		case 5:
			print_loading("이체 준비중...", 800);
			sendToMoney();
			break;
		case 6:
			print_loading("종료중...", 1500);
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
	fprintf(stdout, "입금할 계좌 번호를 입력해주세요 : ");
	int No, money;
	scanf_s("%d", &No);
	if (!findAccount(No)) {
		print_loading("존재하지 않는 계좌 번호 입니다", 1000);
		return;
	}
	fprintf(stdout, "입금할 금액을 입력해주세요 : ");
	scanf_s("%d", &money);
	diposit(No, money);
}

void withdrawMoney() {
	fprintf(stdout, "입금할 계좌 번호를 입력해주세요 : ");
	int No, money;
	scanf_s("%d", &No);
	if (!findAccount(No)) {
		print_loading("존재하지 않는 계좌 번호 입니다", 1000);
		return;
	}
	fprintf(stdout, "출금할 금액을 입력해주세요 : ");
	scanf_s("%d", &money);
	withdraw(No, money);
}

void sendToMoney() {
	fprintf(stdout, "출금할 계좌 번호를 입력해주세요 : ");
	int fromNo, toNo, money;

	scanf_s("%d", &fromNo);
	if (!findAccount(fromNo)) {
		print_loading("존재하지 않는 계좌 번호 입니다", 1000);
		return;
	}

	fprintf(stdout, "이체할 계좌 번호를 입력해주세요 : ");
	scanf_s("%d", &toNo);
	if (!findAccount(toNo)) {
		print_loading("존재하지 않는 계좌 번호 입니다", 1000);
		return;
	}

	fprintf(stdout, "출금할 금액을 입력해주세요 : ");
	scanf_s("%d", &money);

	sendTo(fromNo, toNo, money);
}

void print_loading(const char* mas, int delay) {
	system("cls");
	fprintf(stdout, "%s\n", mas);
	Sleep(delay);
	system("cls");
}