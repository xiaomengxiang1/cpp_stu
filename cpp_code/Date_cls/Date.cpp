#include "Date.h"

int Data::GetMonthDay(int year, int month) const {
    static int month_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
        return 29;
    }
    return month_days[month];
}

//构造函数的缺省参数在声明函数中写好就可以了
Data::Data(int year, int month, int day) {
    //注意构造函数的参数要检查一下
    if (year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month)) {
        _year = year;
        _month = month;
        _day = day;
    }
    else {
        cout << "illegal input" << endl;
    }
}

//d1 < d2
// d1.operator<(&d1, d2);
//bool operator<(Data* this, const Data& d);
bool Data::operator<(const Data& d) const {
    if (_year < d._year)
        return true;
    else if (_year == d._year && _month < d._month)
        return true;
    else if (_year == d._year && _month < d._month && _day < d._day)
        return true;

    return false;
}


bool Data::operator==(const Data& d) const {
    if (_year == d._year && _month == d._month && _day == d._day)
        return true;
    return false;
}

// d1 <= d2
// d1.operator<=(&d1, d2);
bool Data::operator<=(const Data& d) const {    // bool operator<=(Data* this, const Data& d)
    return *this < d || *this == d; // 复用上面的函数实现
}

bool Data::operator>(const Data& d) const {
    return !(*this <= d);   //注意小于等于取反才是大于
}

bool Data::operator>=(const Data& d) const {
    return !(*this < d);
}

bool Data::operator!=(const Data& d) const {
    return !(*this == d);
}

//处理i + 10逻辑和i += 10 逻辑的时候 要注意前面的i是不变的，后面的i变化了,所以要拷贝一个再返回，不要动原来的
Data Data::operator+(int day) const {
    Data ret = *this;   //拷贝  也可以Data ret(*this);
    ret._day += day;
    while (ret._day > GetMonthDay(ret._year, ret._month)) {
        //日期大了，月进一，年同理
        ret._day -= GetMonthDay(ret._year, ret._month);
        ret._month++;

        if (ret._month > 12) {
            ret._year++;
            ret._month = 1;
        }
    }
    return ret;
}

// //复用实现
// Data Data::operator+(int day) {
//     Data ret = *this;
//     ret += day;

//     return ret;
// }


//如果返回值是全局的，那尽量返回引用
Data& Data::operator+=(int day) {
    if (day < 0) {
        return *this -= -day;
    }

    _day += day;
    while (_day > GetMonthDay(_year, _month)) {
        //日期大了，月进一，年同理
        _day -= GetMonthDay(_year, _month);
        _month++;

        if (_month > 12) {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

Data& Data::operator-=(int day) {
    if (day < 0) {
        return *this += -day;
    }

    _day -= day;
    while (_day <= 0) {
        _month--;
        if (_month == 0) {
            _month = 12;
            _year--;
        }

        _day += GetMonthDay(_year, _month);
    }

    return *this;
}

Data Data::operator-(int day) const {
    Data ret = *this;
    ret._day -= day;
    while (ret._day <= 0) {
        ret._month--;

        if (ret._month == 0) {
            ret._month = 12;
            ret._year--;
        }
        ret._day += GetMonthDay(ret._year, ret._month);
    }
    return ret;
}

// //复用实现
// Data operator-(int day) {
//     Data ret = *this;
//     ret -= day;

//     return ret;
// }

//前置++        ++d1
Data& Data::operator++() {
    *this += 1; //复用上面的函数，加上一天

    return *this;
}

//后置++        d1++
Data Data::operator++(int) { //为了构成重载 加一个形参
    Data ret = *this;
    *this += 1;

    return ret;
}
//前置--
Data& Data::operator--() {
    *this -= 1;

    return *this;
}
// 后置--
Data& Data::operator--(int) {
    Data ret = *this;
    *this -= 1;

    return ret;
}

// d1 - d2
int Data::operator-(const Data& d) const {  //成员函数后面的const表示这个函数不会修改调用该函数的对象
    //找出最小的一个日期
    int flag = 1; //  假设为正
    Data max = *this;
    Data min = d;
    if (*this < d) {
        min = *this;
        max = d;
        flag = -1;
    }

    int n = 0;
    while (min != max) {
        ++min;
        ++n;
    }

    return n * flag;
}

void Data::Print() const {
    cout << _year << "-" << _month << "-" << _day << endl;
}