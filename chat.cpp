#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() 
{
    dataCount = 0;
    dataBase = new HashTable();
}
Chat::~Chat()
{
    delete dataBase;
}
//int Chat::hash_func(char _login[LOGINLENGTH], int offset)
//{
//    int sum = 0, i = 0;
//    for (; i < strlen(_login); i++) {
//        sum += _login[i];
//    }
//    // квадратичные пробы
//    return (sum % mem_size + offset * offset) % mem_size;
//}

void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {

    dataBase->add(_login, sha1(_pass, pass_length)); 
    
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {

    uint* digest = sha1(_pass, pass_length);

    bool cmpHashes = !memcmp(
        dataBase->getPassHash(_login),
        digest,
        SHA1HASHLENGTHBYTES);
    delete[] digest;

    return cmpHashes;
}

void Chat::clear()
{
    delete dataBase;
    dataCount = 0;
}

void Chat::del(char _login[LOGINLENGTH])
{
    dataBase->deleteUser(_login);
}