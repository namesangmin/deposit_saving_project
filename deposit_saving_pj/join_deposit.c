#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include "join_deposit.h"
#include "check_rates.h"
#include "ui_system.h"
#include "exit_program.h"

int updateDeposit(float money) {
	system("cls");
	prompt(20, 7); printf("계약금액 %d 원", (int)money);
	prompt(20, 9); printf("입력하신 내용이 맞습니까(y/n)?");
	int isYesNo = getch();
	return isYesNo;
}
// menu3
float inputDeposit() {
	float money;
	(void)scanf(" %f", &money);
	while (getchar() != '\n') {
		money = -1;
	}
	return money;
}

void joinDeposit(bank* bankInfo, user* userInfo){
	float money = 0.0f;

	while (1) {
		system("cls");
		prompt(20, 7); printf("원하시는 예금 액수를 입력하세요: ");
		money = inputDeposit();
		if ((int)money < 0) continue;

		int isTrue = updateDeposit(money);
		if (isTrue == 'Y' || isTrue == 'y') {
			userInfo->amount = money;
			break;
		}
	}

	// 업데이트
	userInfo->amount = money;
	exitBeforeStoreUser(userInfo);
	// 업데이트 확인
	checkRates(bankInfo, userInfo);
}