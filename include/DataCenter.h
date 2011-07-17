class DataCentral
{
    DataCentral();
    ~DataCentral();
    void* getData(String);
    void addData(String,void*);
    void freeData(String);
    void* v_mData;
}
