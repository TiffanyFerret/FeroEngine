#ifndef HASH_TABLE_H
#define HASH_TABLE_H
class Entry
{
public:
    void* data;
    unsigned long long value;
};
class HashTable
{
public:
    HashTable(int);
    ~HashTable();
    std::list<Entry*>* table;
    unsigned long long primeNumber;
    unsigned int mN;
    bool transferDone;

    unsigned int transferIndex;
    unsigned int size;

    HashTable* otherTable;

    unsigned long long hash(std::string);
    Entry* insert(std::string,void*);
    Entry* insert(unsigned long long,void*);
    void* find(std::string);
    Entry* remove(std::string);
    Entry* remove(unsigned long long);
    void clear();
    void transfer(HashTable*);
    void transferAction(unsigned int);

    unsigned int compression(unsigned long long);
};
#endif
