#include <list>
#include <string>
#include "../include/HashTable.h"
#include "../include/DataCenter.h"
DataCentral::DataCentral()
{
    v_mData = new HashTable(256);
}

DataCentral::~DataCentral()
{
    HashTable* data = v_mData;
    delete data;
}
void DataCentral::addData(String fDataName,void* fData)
{
    HashTable* data = v_mData;
    data->insert(fDataname,fData);
}

void* DataCentral::getData(String fDataName)
{
    HashTable* data = v_mData;
    return(data->find(fDataname,fData));
}

void DataCentral::freeData(String fDataName)
{
    HashTable* data = v_mData;
    data->remove(fDataName);
}
