#ifndef  _UI_SYSTEM_H
#define _UI_SYSTEM_H
#include "init_bank_info.h"

typedef struct _menu {
	char* name;
	int (*func)(bank*, user*);
}menu;

void prompt(int xx, int yy);
void runMenuFunc(int select, bank* bankInfo, user* userInfo);
int displayMenu(void);

#endif
