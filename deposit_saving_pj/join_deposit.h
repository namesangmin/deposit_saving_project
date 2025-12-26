#ifndef _JOIN_DEPOSIT_H
#define _JOIN_DEPOSIT_H
#include "init_bank_info.h"

int updateDeposit(float money);
float inputDeposit();
void joinDeposit(bank* bankInfo, user* userInfo);

#endif
