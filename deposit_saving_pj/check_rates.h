#ifndef _CHECK_RATES_H
#define _CHECK_RATES_H
#include "init_bank_info.h"

float calcMyInterest(bank* bankInfo, user* userInfo);
float calcMyAfterMoney(bank* bankInfo, user* userInfo);
void checkRates(bank* bankInfo, user* userInfo);

#endif
