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

#include <iostream>
using namespace std;
class Stack {
    public:
        Stack(int n = 10) {
            _a = (int*)malloc(sizeof(int) * n);
            _size = 0;
            _capacity = 10;

            cout << "malloc:" << _a  << endl;
        }

        //析构函数
        ~Stack() {
            free(_a);
            cout << "free:" << _a << endl;

            _a = nullptr;
            _size = 0;
            _capacity = 0;   
        }

    private:
        int* _a;
        int _size;
        int _capacity;
};
int main() {
    Stack st1;
    Stack st2;
    // 创建栈帧从上到下，销毁从下到上，根据栈的特性
    // malloc:0x7f4590
    // malloc:0x7f45f0
    // free:0x7f45f0
    // free:0x7f4590
    return 0;
}