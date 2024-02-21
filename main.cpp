#include <iostream>
#include "chat.h"

int main()
{
	Chat ch;
	char pass1[] = "qwerty12345";
	char login1[] = "Amir";
	ch.reg(login1, pass1, sizeof(pass1) - 1);

	char pass2[] = "123123123";
	char login2[] = "Durak";
	ch.reg(login2, pass2, sizeof(pass2) - 1);

	cout << ch.login(login2, pass2, sizeof(pass2) - 1) << endl;
}
