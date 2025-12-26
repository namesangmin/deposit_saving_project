#ifndef _INIT_BANK_INFO_H
#define _INIT_BANK_INFO_H
#define DEMOAMOUNT 1000000 // 백만원
#define PERCENTAGE 0.01
#define BUFFER_SIZE 10
#define MENU_MIN 1
#define MENU_MAX 4
typedef struct bank_info {
	// 전국은행고시율 확인 https://portal.kfb.or.kr/compare/receiving_neosearch.php
	float PreTaxRate; //세전금리
	float AfterTaxRate; //세후금리
	float HighestPreferRate; //최고우대금리
	float MidCancelRate; //중도해지금리
	char* InterestCalcMethod; //이자계산방식(단리)
}bank;

typedef struct {
	float amount;       // 원금 (금액이 클 수 있으므로 double)
	float MyInterestAfterTaxRate; // 세후 이자
	float EstimatedAmount;     // 만기 예상 금액
}user;

bank* loadBankData();
user* loadUserData();
#endif
