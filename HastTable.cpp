#include "HashTable.h"

HashTable::HashTable()
{
    mem_size = 8;
    userArray = new Pair[mem_size];
}

HashTable::~HashTable()
{
    delete[] userArray;
}

void HashTable::resize()
{
    Pair* save = userArray;
    int save_ms = mem_size;

    mem_size *= 2;
    userArray = new Pair[mem_size];
    
    for (int i = 0; i < save_ms; i++) {
        Pair& old_pair = save[i];
        if (old_pair.status == enPairStatus::engaged) {
            add(old_pair.user_login, old_pair.user_pass);
        }
    }

    delete[] save;
}

void HashTable::add(login _user_login, uint* _user_pass)
{
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(_user_login, i);
        if (userArray[index].status != enPairStatus::engaged) {
            // найдена пустая ячейка, занимаем ее
            break;
        }
    }
    if (i >= mem_size)
    {
        resize();
        add(_user_login, _user_pass);
    } // все перебрали, нет места
    else
    {
        // кладем в свободную ячейку пару
        userArray[index] = Pair(_user_login, _user_pass);
    }

}

int HashTable::hash_func(login user_login, int offset)
{
    int index = -1, i = 0;

    const float A = 0.7;
    float midVal;

    int sum = 0;
    for (; i < strlen(user_login); i++)
    {
        sum += user_login[i];
    }

    midVal = sum / i;

    int num = int(mem_size * (A * midVal - int(A * midVal)));

    return (num % mem_size + offset * offset) % mem_size;
}

void HashTable::display()
{
    for (int i = 0; i < mem_size; i++)
    {
        cout << userArray[i].user_login << " " << userArray[i].user_pass     << " " << userArray[i].status << "\n";
    }
}

int HashTable::find(login _user_login)
{
    int ind = -1, i = 0;
    for (; i < mem_size; i++)
    {
        ind = hash_func(_user_login, i);
        if (userArray[ind].status == free)
        {
            return -1;
        }
        if (!strcmp(userArray[ind].user_login, _user_login))
        {
            return ind;
        }
    }
    
    return -1;
}

void HashTable::deleteUser(login _user_login)
{
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(_user_login, i);
        if (userArray[index].status == enPairStatus::engaged &&
            !strcmp(userArray[index].user_login, _user_login)) {
            userArray[index].status = enPairStatus::deleted;
            return;
        }
        else if (userArray[index].status == enPairStatus::free) {
            return;
        }
    }
    
    
}

uint* HashTable::getPassHash(login usr_login)
{
    int ind = find(usr_login);
    if (ind != -1)
    {
        return userArray[ind].user_pass;
    }
    return nullptr;

}
