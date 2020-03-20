经过查阅，发现有这样的写法
```c++
struct record{
    string num;
    string file;
    mutable int count;
    record(string n,string f):num(n),file(f),count(1){}
};
bool operator==(const struct  record & X,const struct record & Y)
{
    //return hash<string>()(X.num+X.file)==hash<string>()(Y.num+Y.file);
    return (Y.num==X.num)&&(Y.file==X.file);
}


struct record_hash{
    size_t operator()(const struct record& _r) const {
    string tmp=_r.file+_r.num;
    return std::hash<string>()(tmp);
    }
};
int main()
{
    unordered_set<record,record_hash> records;
    records.insert(record("zhang","xiao"));
    record r("zhang","xiao");
    auto it = records.find(r);
    cout<<it->num<<" "<<it->file<<endl;
    return 0;
```

实际上，unorderd_set 初始化的时候，需要两个内容,一个是要重载运算符==（和<,>玩法类似）
另外就是要另外写一个结构体hash_key，重载
```c++



```