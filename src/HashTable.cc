#include <list>
#include <string>
#include <iostream>
#include <queue>
#include "../include/HashTable.h"
// supports up to 13 letters long
HashTable::HashTable(int N)
{
    //biggest prime that will fit in 64 bits
    primeNumber = 1024628340621757567;
    mN = N - 1;
    size = 0;
    otherTable = 0;
    transferDone = false;
    transferIndex = 0;
    table = new list<Entry*>[N];
}

HashTable::~HashTable()
{
    clear();
}
unsigned long long HashTable::hash(std::string key)
{
    unsigned long long value = 0;
    unsigned long long letterDigit = 1;
    unsigned int letter = 0;
    for(unsigned int i = 0;i < (key.length());i++)
    {
        if(i == (key.length() - 1))
        {
            letter = letterDigit * (key[i] - 96);
        }
        else
        {
            letter = letterDigit * (key[i] - 'a');
        }
        value = value + letter;
        letterDigit = letterDigit * 26;
    }
    return value;
}
Entry* HashTable::insert(std::string key,void* data)
{
    unsigned long long value = hash(key);
    Entry* tmp = new Entry();
    tmp->data = data;
    tmp->value = value;
    table[compression(value)].push_back(tmp);
    size = size + 1;
    return tmp;
}
Entry* HashTable::insert(unsigned long long value,void* data)
{
    Entry* tmp = new Entry;
    tmp->data = data;
    tmp->value = value;
    table[compression(value)].push_back(tmp);
    size = size + 1;
    return tmp;
}
void* HashTable::find(std::string key)
{
    std::list<Entry*>::iterator it;
    unsigned long long value = hash(key);
    unsigned int location = compression(value);
    for(it = table[location].begin(); it != table[location].end();it++)
    {
        Entry* itTmp = *it;
        if(itTmp->value == value)
        {
            return itTmp->data;
        }
    }
    if(otherTable != 0)
    {
        value = otherTable->hash(key);
        location = otherTable->compression(value);
        for(it = otherTable->table[location].begin(); it != otherTable->table[location].end();it++)
        {
            Entry* itTmp = *it;
            if(itTmp->value == value)
            {
                return itTmp->data;
            }
        }
    }
    return 0;
}
Entry* HashTable::remove(std::string key)
{
    unsigned long long value = hash(key);
    Entry* entry = 0;
    Entry* tmp;
    std::list<Entry*>::iterator it;
    std::list<Entry*>::iterator* itPtr;
    unsigned int location = compression(value);
    for(it = table[location].begin(); it != table[location].end();it++)
    {
        Entry* itTmp = *it;
        if(itTmp->value == value)
        {
            entry = new Entry();
            entry->data = itTmp->data;
            entry->value = itTmp->value;
            itPtr = &it;
            size = size - 1;
        }
    }
    if(entry != 0)
    {
        table[location].erase(*itPtr);
        return entry;
    }
    else
    {
        return 0;
    }
}

void HashTalbe::clear()
{
    for(unsigned int i = 0;i < mN;i++)
    {
        table[i]->clear();
    }
}
void HashTable::transfer(HashTable* other)
{
    otherTable = other;
}
void HashTable::transferAction(unsigned int actions)
{
    unsigned int i;
    for(i = transferIndex;i < (transferIndex + actions);i++)
    {
        std::queue<std::list<Entry*>::iterator> removeQueue;
        std::list<Entry*>::iterator it;
		if(size == 0 || i >= mN - 1)
        {
            transferDone = true;
            return;
        }
        for(it = table[i].begin(); it != table[i].end();it++)
        {
            Entry* itTmp = *it;
            unsigned long long value;
            void* data;
            removeQueue.push(it);
            value = itTmp->value;
            data = itTmp->data;

            size = size - 1;
            otherTable->insert(value,data);
        }
        while(removeQueue.empty() == false)
        {
            table[i].erase(removeQueue.front());
            removeQueue.pop();
        }
    }
    transferIndex = transferIndex + i;
}
unsigned int HashTable::compression(unsigned long long key)
{
    return(key % primeNumber % mN);
}
