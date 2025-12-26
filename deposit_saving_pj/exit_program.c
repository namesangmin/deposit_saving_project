#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "exit_program.h"
#include "ui_system.h"

int exitBeforeStoreBank(bank* bankInfo) {
    FILE* bankFp;
    bankFp = fopen("bank_info.txt", "w");
    if (bankFp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    // float* → float로 변경
    (void)fprintf(
        bankFp,
        "%.02f %.02f %s %.02f %.02f",
        bankInfo->AfterTaxRate,
        bankInfo->HighestPreferRate,
        bankInfo->InterestCalcMethod,
        bankInfo->MidCancelRate,
        bankInfo->PreTaxRate
    );
    fclose(bankFp);
    return 0;
}

int exitBeforeStoreUser(user* userInfo) {
    FILE* userFp;
    userFp = fopen("user_info.txt", "w");
    if (userFp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    printf("%f", userInfo->amount);
    (void)fprintf(userFp, "%f %f %f", 
        userInfo->amount, 
        userInfo->EstimatedAmount, 
        userInfo->MyInterestAfterTaxRate);
    fclose(userFp);
    return 0;
}

void exitProgram(bank* bankInfo, user* userInfo) {
    // 파일 저장 하고 종료
    exitBeforeStoreBank(bankInfo);
    exitBeforeStoreUser(userInfo);
    //system("cls");
    prompt(20, 20); printf("------------------------------------------------------------------------");
    prompt(20, 22); printf("written by : 이상민");
    prompt(20, 24); printf("------------------------------------------------------------------------");

    free(bankInfo->InterestCalcMethod);
    free(bankInfo);
    free(userInfo);
}