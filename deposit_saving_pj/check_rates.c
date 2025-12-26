#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include "check_rates.h"
#include "ui_system.h"

float calcMyInterest(bank* bankInfo, user* userInfo) {
	return (float)(PERCENTAGE * bankInfo->AfterTaxRate * userInfo->amount);
}

float calcMyAfterMoney(bank* bankInfo, user* userInfo) {
	return (float)(PERCENTAGE * bankInfo->AfterTaxRate * userInfo->amount + userInfo->amount);
}

void checkRates(bank* bankInfo, user* userInfo) {
	system("cls");
	prompt(20, 7); printf("나의 예상 수익율 확인(%d 원 입금 기준)", (int)userInfo->amount);
	prompt(20, 9); printf("세전금리 세후금리 최고우대금리 중도해지금리 이자계산방식 세후이자 만기시예상금액");
	prompt(20, 11); printf("----------------------------------------------------------------------------------");
	prompt(20, 13); printf("  %.02f	%.02f	   %.02f	        %.02f	    %2s       %8d     %10d", 
		bankInfo->PreTaxRate, 
		bankInfo->AfterTaxRate, 
		bankInfo->HighestPreferRate, 
		bankInfo->MidCancelRate, 
		bankInfo->InterestCalcMethod, 
		(int)calcMyInterest(bankInfo, userInfo), 
		(int)calcMyAfterMoney(bankInfo, userInfo));
	prompt(20, 15); printf("----------------------------------------------------------------------------------");
	prompt(20, 17); printf("# 아무키나 입력하면 메인 메뉴로 돌아갑니다");
	(void)_getch();
}
