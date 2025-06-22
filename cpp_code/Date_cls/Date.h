#pragma once
#include <iostream>
using namespace std;
class Data {
public:
    int GetMonthDay(int year, int month) const;
    //构造函数
    Data(int year = 1, int month = 1, int day = 1);

    bool operator<(const Data& d) const;
    bool operator==(const Data& d) const;
    bool operator<=(const Data& d) const;
    bool operator>(const Data& d) const;
    bool operator>=(const Data& d) const;
    bool operator!=(const Data& d) const;
    Data operator+(int day) const;
    Data& operator+=(int day);
    Data& operator-=(int day);
    Data operator-(int day) const;
    Data& operator++();
    Data operator++(int);
    //前置--
    Data& operator--();
    // 后置--
    Data& operator--(int);
    // d1 - d2
    int operator-(const Data& d) const;
    //打印
    void Print() const;

private:
    int _year;
    int _month;
    int _day;
};
