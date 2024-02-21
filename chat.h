#pragma once

#include "sha1.h"
#include "string.h"
#include "HashTable.h"

#define LOGINLENGTH 10

class Chat {
public:
    Chat();
    ~Chat();
    void reg(char _login[LOGINLENGTH], char _pass[], int pass_length);
    bool login(char _login[LOGINLENGTH], char _pass[], int pass_length);
    void del(char _login[LOGINLENGTH]);

    void clear();
private:
   // enum enPairStatus
   // {
   //     free,
   //     engaged,
   //     deleted
   // };
   // struct AuthData {
   //     AuthData() :
   //         login(""),
   //         pass_sha1_hash(0),
   //         status(free) {
   //     }
   //     ~AuthData() {
   //         if (pass_sha1_hash != 0)
   //             delete[] pass_sha1_hash;
   //     }
   //     AuthData(char _login[LOGINLENGTH], uint* sh1, enPairStatus st) {
   //         strcpy_s(login, _login);
   //         pass_sha1_hash = sh1;
   //         status = st;
   //     }
   //     AuthData& operator = (const AuthData& other) {
   //         strcpy_s(login, other.login);
   //         status = other.status;
   //         if (pass_sha1_hash != 0)
   //             delete[] pass_sha1_hash;
   //         pass_sha1_hash = new uint[SHA1HASHLENGTHUINTS];
   //         memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);
   //         return *this;
   //     }
   //     char login[LOGINLENGTH];
   //     uint* pass_sha1_hash;
   //     enPairStatus status;
   // };*/
    //int hash_func(char _login[LOGINLENGTH], int offset);
    //AuthData* data;
    //int mem_size;
    //int data_count;
    HashTable* dataBase;
    int dataCount;
    /*int Count;*/
};