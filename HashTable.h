#pragma once
#include "sha1.h"
#include <string.h>
#include <iostream>

using namespace std;

#define LOGINLENGTH 10

typedef char login[LOGINLENGTH];

class HashTable
{
public:
	
	HashTable();
	~HashTable();

	void add(login, uint*);

	void resize();
	int find(login);
	void deleteUser(login);

	uint* getPassHash(login);

	void display();

private:
	enum enPairStatus
	{
		free,
		engaged,
		deleted
	};

	struct Pair
	{
		Pair():
			user_login(""),
			user_pass(0),
			status(free) {
		}

		Pair(login _user_login, uint* _user_pass)
		{
			strcpy_s(user_login, _user_login);

			if (user_pass[0] == 0)
			{
				delete user_pass; 
			}
			user_pass = new uint[SHA1HASHLENGTHUINTS];

			memcpy(this->user_pass, _user_pass, SHA1HASHLENGTHBYTES);

			status = engaged;
		}

		/*Pair(login _user_login, uint* _user_pass, enPairStatus _status)
		{
			strcpy_s(this->user_login, _user_login);

			if (user_pass != 0)
				delete[] user_pass;
			user_pass = new uint[SHA1HASHLENGTHUINTS];

			memcpy(this->user_pass, _user_pass, SHA1HASHLENGTHBYTES);

			status = _status;
		}*/

		~Pair()
		{
			if (user_pass != 0)
				delete[] user_pass;
		}

		Pair& operator=(const Pair& other)
		{
			//cout << this->user_pass << endl;

			strcpy_s(user_login, other.user_login);
			if (user_pass != 0)
			{
				delete[] user_pass;
			}
			user_pass = new uint[SHA1HASHLENGTHUINTS];

			memcpy(user_pass, other.user_pass, SHA1HASHLENGTHBYTES);
			status = other.status;

			return *this;
		}


		login user_login;
		uint* user_pass;
		enPairStatus status;
	};
	
	int hash_func(login, int);

	Pair* userArray;
	int mem_size;
};