#ifndef _EXIT_PROGRAM_H
#define _EXIT_PROGRAM_H
#include "init_bank_info.h"

int exitBeforeStoreBank(bank* bankInfo);
int exitBeforeStoreUser(user* userInfo);
void exitProgram(bank* bankInfo, user* userInfo);
#endif
