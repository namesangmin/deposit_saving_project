#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include "calc_profit.h"
#include "check_rates.h"
#include "exit_program.h"
#include "join_deposit.h"
#include "ui_system.h"

// 음 이거 헤더파일에 넣으면 함수들이 없어서 오류가 남 -> .c에 다른 함수들이 include되어 있으니 
// 여기서만 만들 수 있어
static menu choiceMenu[] = {
	// 나중에 [ ] 안에 값을 지우고, 아래 메뉴에서 주석 처리를 하면 그 함수만 실행하지 않도록 할 수 있음
	// 추가, 수정, 삭제 가능
	{"",0},
	{"은행 현재 고시 이자율", calcProfit},
	{"나의 예상 수익율 확인", checkRates},
	{"정기 예금 가입하기", joinDeposit},
	{"종료하기", exitProgram}
};

// prompt
void prompt(int xx, int yy){
	COORD locate = { xx - 1, yy - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), locate);
}

// 입력한 함수 실행
void runMenuFunc(int select, bank* bankInfo, user* userInfo) {
	if (select < MENU_MIN || select > MENU_MAX) return;
	choiceMenu[select].func(bankInfo, userInfo);
}

// 메인 화면 출력
// prompt에 상수들을 모두 define으로 처리해야 함
int displayMenu(void) {
	int select = 0;
	int menuSize = sizeof(choiceMenu)/ sizeof(choiceMenu[0]);
	system("cls");
	for (int i = 1; i < menuSize; i++) {
		prompt(30, 4 + i * 2);
		printf("%2d. %s", i, choiceMenu[i].name);
	}
	while (select < '1' || select > '4') {
		prompt(25, 17); printf("* 원하시는 메뉴를 선택하세요 : _\b");
		select = getchar();
		fflush(stdin);
	}
	select -= '0';
	return(select);
}