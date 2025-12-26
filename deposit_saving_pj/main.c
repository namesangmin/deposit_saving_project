#include <stdio.h>
#include "ui_system.h"
#include "init_bank_info.h"

int main(void){
	// 초기화(파일 불러오기)
	bank* bankInfo = loadBankData();
	user* userInfo = loadUserData();
	if (bankInfo == NULL || userInfo == NULL) {
		printf("비정상 종료\n");
		return 1;
	}

	while (1) {
		// 값을 받아와서 기능 1~4 실행
		int choice = displayMenu();
		runMenuFunc(choice, bankInfo, userInfo);
		if(choice== 4) break;
	}
	return 0;
}
