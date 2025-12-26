#pragma once
#ifndef _CALC_PROFIT_H
#define _CALC_PROFIT_H
#include "init_bank_info.h"

float calcInterest(bank* bankInfo);
float calcAfterMoney(bank* bankInfo);
void calcProfit(bank* bankInfo, user* userInfo);

#endif
