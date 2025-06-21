// -------------------------构造函数---------------------------------

// 1. 函数名与类名相同。
// 2. 无返回值。
// 3. 对象实例化时编译器自动调用对应的构造函数。
// 4. 构造函数可以重载。

// #include <iostream>
// using namespace std;
// class Data{
//     public:
//     //构造函数，在对象构造时自动调用的函数，这个函数完成初始化工作
//         Data(int year, int month, int day) {
//             _year = year;
//             _month = month;
//             _day = day;
//         }
//         //进行重载，有可能有不想传递参数的时候，这时候使用下面的值进行初始化
//         Data() {
//             _year = 0;
//             _month = 1;
//             _day = 1;
//         }
//         void Init(int year, int month, int day) {
//             _year = year;
//             _month = month;
//             _day = day;
//         }
//         void Show() {
//             cout << _year << "-" << _month << "-" << _day << endl;
//         }
//     private:
//         int _year;
//         int _month;
//         int _day;
// };
// int main() {
//     Data d1(2025, 6, 11);
//     d1.Show();

//     Data d2;   //这里不能带括号，这里是c++语法的规定，不用太纠结，记住就好了
//     d2.Show(); 
//     return 0;
// }

// --------------------没有显式定义时构造函数c++做了什么------------------------------

// #include <iostream>
// using namespace std;
// class Time {
//     public:
//     //构造函数
//         Time() {
//             _hour = 0;
//             _minute = 0;
//             _second = 0;
//         }
//     private:
//         int _hour;
//         int _minute;
//         int _second;
// };
// class Data{
//     public:
//     // 我们没有显式定义构造函数，这里编译器生成无参默认构造函数
//     // 默认生成无参构造函数（语法坑：双标狗）
//     // 1、针对内置类型的成员变量没有做处理
//     // 2、针对自定义类型的成员变量，调用它的构造函数初始化

//     //并且一旦定义了构造函数，编译器就不会生成无参默认构造函数，就需要用自己的构造函数
//         void Show() {
//             cout << _year << "-" << _month << "-" << _day << endl;
//         }
//     private:
//         int _year;
//         int _month;
//         int _day;

//         Time _T;
// };
// int main() {
//     Data d1;
//     d1.Show();
//     return 0;
// }

//定义构造函数可以使用全缺省参数，这样想传几个参数就传几个参数，如下；
// #include <iostream>
// using namespace std;
// class Time {
//     public:
//     //构造函数->全缺省参数
//         Time(int hour = 0, int minute = 0, int second = 0) {
//             _hour = hour;
//             _minute = minute;
//             _second = second;
//         }
//     private:
//         int _hour;
//         int _minute;
//         int _second;
// };
// int main() {
//     //想传几个传几个
//     Time t1;
//     Time t2(1);
//     Time t3(1, 2);
//     Time t4(1, 2, 3);
//     return 0;
// }

// 无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
// 注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为
// 是默认构造函数：
// #include <iostream>
// using namespace std;
// class Time {
//     public:
//     // 无参的构造函数
//         Time() {
//             _hour = 1;
//             _minute = 1;
//             _second = 1;
//         }
//         // 全缺省的构造函数
//         Time(int hour = 0, int minute = 0, int second = 0) {
//             _hour = hour;
//             _minute = minute;
//             _second = second;
//         }
//     private:
//         int _hour;
//         int _minute;
//         int _second;
// };
// int main() {
//     Time t1;    //编译不通过，因为产生了歧义，不知道要调用哪一个构造函数
//     return 0;
// }

// --------------------------------析构函数------------------------------

// 1.析构函数名是在类名前加上字符 ~
// 2.无参数无返回值。
// 3.一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
// 4.对象生命周期结束时，C++ 编译系统系统自动调用析构函数。

// #include <iostream>
// using namespace std;
// class Stack {
//     public:
//         Stack(int n = 10) {
//             _a = (int*)malloc(sizeof(int) * n);
//             _size = 0;
//             _capacity = 10;

//             cout << "malloc:" << _a  << endl;
//         }

//         //析构函数
//         ~Stack() {
//             free(_a);
//             cout << "free:" << _a << endl;

//             _a = nullptr;
//             _size = 0;
//             _capacity = 0;   
//         }

//     private:
//         int* _a;
//         int _size;
//         int _capacity;
// };
// int main() {
//     Stack st1;
//     Stack st2;
//     // 创建栈帧从上到下，销毁从下到上，根据栈的特性
//     // malloc:0x7f4590
//     // malloc:0x7f45f0
//     // free:0x7f45f0
//     // free:0x7f4590
//     return 0;
// }


// --------------------没有显式定义时析构函数c++做了什么------------------------------

// 和构造函数差不多，没有显式定义系统会自动生成默认的析构函数,

// #include <iostream>
// using namespace std;
// class Time {
//     public:
//         Time(int hour = 0, int minute = 0, int second = 0) {
//             _hour = hour;
//             _minute = minute;
//             _second = second;
//         }

//         ~Time() {
//             cout << "Time()" << this << endl;
//         }
//     private:
//         int _hour;
//         int _minute;
//         int _second;
// };
// class Data {
//     public:
//         //构造
//         Data(int year = 0, int month = 0, int day = 0) {
//             _year = year;
//             _month = month;
//             _day = day;
//         }

//     private:
//         int _year;
//         int _month;
//         int _day;

//         //系统对于内置类型/基本类型     int/char等等不会进行处理
//         //对于自定义类型    调用它的构造函数初始化/以及析构函数清理资源
//         Time _t;
// };


// int main() {
//     Data d;
//     // 生命周期结束后
//     // Time()0x61fdfc   Data类中没有析构函数，调用了系统的析构函数
//     return 0;
// }

// --------------------------------拷贝构造------------------------------------

// 1.拷贝构造函数是构造函数的一个重载形式。
// 2. 拷贝构造函数的参数只有一个且必须是类类型对象的引用，使用传值方式编译器直接报错，
// 因为会引发无穷递归调用。

// class Date
// {
// public:
//     Date(int year = 1900, int month = 1, int day = 1)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     // Date(const Date d) // 错误写法：编译报错，会引发无穷递归
//     Date(const Date& d) // 正确写法
//     {
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }
// private:
//     int _year;
//     int _month;
//     int _day;
// };
// int main()
// {
//     Date d1;
//     //两种写法
//     Date d2(d1);
//     Date d3 = d1;   //这种写法好像是在进行赋值操作，但实际上它属于初始化的范畴。
//                     //在 C++ 里，当使用 = 对对象进行初始化时，编译器会把它解释为调用拷贝构造函数，
//                     //而非赋值运算符
//     return 0;
// }
// 会引发无穷递归的原因在于，直接传值会先将形参拷贝一份即Date d = d1;   等价于  Date d(d1),而d1还要进行拷贝
// 使用引用就避免了这个问题，等价于Date& d = d1;

// 下面的代码没有定义拷贝构造和=的运算符重载，还能正常工作，并且功能一样，为什么呢？
// #include <iostream>
// using namespace std;
// class Date {
//     public:
//         Date(int year = 0, int month = 0, int day = 0) {
//             _year = year;
//             _month = month;
//             _day = day;
//         }

//         void Print() {
//             cout << _year << "-" << _month << "-" << _day << endl;
//         }

//     private:
//         int _year;
//         int _month;
//         int _day;
// };
// // 1、我们不实现时，编译器生成的默认构造函数和析构函数。
// // 针对成员变量：内置类型就不处理，自定义类型会调这个成员对象的构造和
// // 析构。
// // 2、我们不实现时，编译器生成拷贝构造和 operator=，会完成按字节的值拷贝（浅拷贝）
// // 也就是说有些类，我们是不需要去实现拷贝构造和 operator = 的，因为编译器默认生成就可以用。比如：Date 就是这样
// int main() {
//     Date d1(2020, 4, 11);
//     Date d2(2020, 4, 15);
//     d1 = d2;
//     d1.Print();
//     d2.Print();

//     Date d3(d1);
//     Date d4 = d1;
//     d3.Print();
//     d4.Print();
//     return 0;
// }

// 不自己定义拷贝构造和 operator=  用系统生成的浅拷贝,在一些场景还是有局限性的
// 如Stack这个类：
// 如果将st1 拷贝给st2, 拷贝的过程中指向数组的指针地址会被直接拷贝,导致指向的是同一个数组空间
// 释放空间的时候就会导致同一块空间释放多次,导致报错


// -------------------------------赋值运算符重载----------------------------------

// 自定义类型不能使用运算符，通过operator可以实现运算符重载
// 函数名字为：关键字operator后面接需要重载的运算符符号
// 如operator==() {}  这个重载了==

// 不能通过连接其他符号来创建新的操作符：比如operator@
// 重载操作符必须有一个类类型参数
// 用于内置类型的运算符，其含义不能改变，例如：内置的整型+，不 能改变其含义
// 作为类成员函数重载时，其形参看起来比操作数数目少1，因为成员函数的第一个参数为隐藏的this
// .* :: sizeof ?: . 注意以上5个运算符不能重载。这个经常在笔试选择题中出现。

//这里的成员是公有的
// class Date {
//     public:
//         Date(int year = 0, int month = 0, int day = 0) {
//             _year = year;
//             _month = month;
//             _day = day;
//         }
//         int _year;
//         int _month;
//         int _day;
// };

// bool operator==(const Date& d1, const Date& d2) {
//     return d1._day == d2._day
//         && d1._month == d2._month
//         && d1._year == d2._year;
// }

// int main() {
//     Date d1(2025, 12, 4);
//     Date d2(2025, 12, 4);
//     int ret = (d1 == d2);  //相当于 operator==(d1 == d2);
//     return 0;
// }


//这里的成员是私有的
// class Date {
//     public:
//         Date(int year = 0, int month = 0, int day = 0) {
//             _year = year;
//             _month = month;
//             _day = day;
//         }
//         //封装进去内部      //这里相当于bool operator==(Date* this, const Date& d)
//         bool operator==(const Date& d) {
//             return d._day == _day
//                 && d._month == _month
//                 && d._year == _year;
//         }

//         // d1 > d2
//         //d1.operate>(d2)
//         bool operator>(const Date& d) {
//             if (_year > d._year)
//                 return true;
//             else if (_year == d._year && _month > d._month)
//                 return true;
//             else if (_year == d._year && _month == d._month && _day > d._day)
//                 return true;

//             return false;
//         }
//     private:
//         int _year;
//         int _month;
//         int _day;
// };


// int main() {
//     Date d1(2025, 12, 4);
//     Date d2(2025, 12, 4);
//     int ret1 = d1.operator==(d2);
//     int ret2 = d1.operator==(d2);
//     return 0;
// }


// -------------------------------日期类的实现----------------------------------

#include <iostream>
using namespace std;
class Data {
    public:
        int GetMonthDay(int year, int month) {
            static int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
                return 29;
            }
            return month_days[month];
        }

        Data(int year = 1, int month = 1, int day = 1) {
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

        Data(const Data& d) {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        //d1 < d2
        // d1.operator<(&d1, d2);
        //bool operator<(Data* this, const Data& d);
        bool operator<(const Data& d) {
            if (_year < d._year)
                return true;
            else if (_year == d._year && _month < d._month)
                return true;
            else if (_year == d._year && _month < d._month && _day < d._day)
                return true;

            return false;
        }

        bool operator==(const Data& d) {
            if (_year == d._year && _month == d._month && _day == d._day)
                return true;
            return false;
        }

        // d1 <= d2
        // d1.operator<=(&d1, d2);
        bool operator<=(const Data& d) {    // bool operator<=(Data* this, const Data& d)
            return *this < d || *this == d; // 复用上面的函数实现
        }

        bool operator>(const Data& d) {
            return !(*this <= d);   //注意小于等于取反才是大于
        }

        bool operator>=(const Data& d) {
            return !(*this < d); 
        }

        bool operator!=(const Data& d) {
            return !(*this == d); 
        }

        //处理i + 10逻辑和i += 10 逻辑的时候 要注意前面的i是不变的，后面的i变化了,所以要拷贝一个再返回，不要动原来的
        Data operator+(int day) {
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
        // Data operator+(int day) {
        //     Data ret = *this;
        //     ret += day;

        //     return ret;
        // }


        //如果返回值是全局的，那尽量返回引用
        Data& operator+=(int day) {
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

        Data& operator-=(int day) {
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

        Data operator-(int day) {
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
        Data& operator++() {
            *this += 1; //复用上面的函数，加上一天

            return *this;
        }

        //后置++        d1++
        Data operator++(int) { //为了构成重载 加一个形参
            Data ret = *this;
            *this += 1;

            return ret;
        }
        //前置--
        Data& operator--() {
            *this -= 1;

            return *this;
        }
        // 后置--
        Data& operator--(int) {
            Data ret = *this;
            *this -= 1;

            return ret;
        }

        

        void Print() {
            cout << _year << "-" << _month << "-" << _day << endl;
        }

    private:
        int _year;
        int _month;
        int _day;
};

// int main() {
//     Data d1(2020, 4, 11);
//     d1.Print();

//     Data d2(2020, 2, 29);
//     d2.Print();

//     //非法输入，打印随机值
//     //Data d3(2021, 4, 31);
//     //d3.Print();

//     cout << (d1 > d2) << endl;
//     cout << (d1 < d2) << endl;
//     cout << (d1 == d2) << endl;
//     cout << (d1 != d2) << endl;
//     cout << (d1 <= d2) << endl;
//     cout << (d1 >= d2) << endl;

//     // 是否要重载一个运算符，看的是这个运算符是否对这个类的对象有意义
//     Data d4 = d1 + 100;
//     d4.Print();
//     // d1 += 10;
//     // d1 - 10;
//     // d1 -= 10;
//     // d1 - d1;
//     // d1++;
//     // d1--;

//     return 0;
// }

