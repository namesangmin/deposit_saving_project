#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "init_bank_info.h"
#include "ui_system.h"
// 파일을 읽어와서 거기에 저장되어 있는 값들을 불러온다.
// 저장하는 방식은 동적할당을 한다.
bank* loadBankData() {
	FILE* fp;
	// 파일을 읽어와서 저장한다.
	fp = fopen("bank_info.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return NULL;
	}

	bank *bankInfo = (bank*)malloc(sizeof(bank));
	if (bankInfo == NULL) {
		printf("bank 메모리 할당 실패\n");
		return NULL;
	}

	bankInfo->InterestCalcMethod = (char*)malloc(sizeof(char) * 10);
	if (bankInfo->InterestCalcMethod == NULL) {
		printf("메모리 할당 실패\n");
		free(bankInfo);
		return NULL;
	}

	(void)fscanf(fp, "%f %f %s %f %f",
		&bankInfo->AfterTaxRate, 
		&bankInfo->HighestPreferRate, 
		bankInfo->InterestCalcMethod,
		&bankInfo->MidCancelRate, 
		&bankInfo->PreTaxRate);
	fclose(fp);
	return bankInfo;
}

user* loadUserData() {
	FILE* fp;

	// 파일을 읽어와서 저장한다.
	fp = fopen("user_info.txt", "r");
	if (fp == NULL) {
		printf("파일 열기 실패\n");
		return NULL;
	}
	// 파일 없으면 새로 만들기
	user* userInfo = (user*)malloc(sizeof(user));
	if (userInfo == NULL) {
		printf("user 메모리 할당 실패\n");
		return NULL;
	}

	(void)fscanf(fp, "%f %f %f",
		&userInfo->amount,
		&userInfo->EstimatedAmount, 
		&userInfo->MyInterestAfterTaxRate);
	fclose(fp);
	return userInfo;
}