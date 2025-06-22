// -------------------------------再谈构造函数----------------------------------

// 1.每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
// 2. 类中包含以下成员，必须放在初始化列表位置进行初始化：
//         引用成员变量
//         const成员变量
//         自定义类型成员(且该类没有默认构造函数时)
// 3. 尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于自定义类型成员变量，
// 一定会先使用初始化列表初始化。
// 4. 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后
// 次序无关

//为什么有初始化列表？
// class Date
// {
//     public:
//         // Date(int year, int month, int day)
//         // {
//         // _year = year;
//         // _month = month;
//         // _day = day;
//         // }

//         //列表初始化  //这里相当于成员的定义
//         Date(int year, int month, int day)   
//             :_year(year)
//             ,_month(month)
//             ,_day(day)
//             {}

//     private:
            //这里相当于成员的声明
//         int _year;
//         int _month;
//         int _day;
// };


// -------------------------------static成员----------------------------------

// 计算一个类被生产了几次
// #include <iostream>
// using namespace std;
// class A {
//     public:
//         A() {
//             ++n;
//         }

//         A(const A& a) {
//             ++n;
//         }

//         static int GetN() {     //静态的函数，没有this指针，函数不能访问非静态的成员
//             return n;
//         }
//     private:
//         static int n;   //声明，不是属于某一个对象，是属于类的所有对象，属于这个类
//                         // n不在对象中，在静态区
// };

// int A::n = 0;  //定义

// A& func(A& a) {
//     return a;
// }

// int main() {
//     A a1;
//     A a2;

//     func(a1);
//     func(a2);

//     //调用静态函数由于没有this指针，所以并不需要用对象来进行调用，可以直接用类调用
//     a1.GetN();  //ok
//     cout << A::GetN() << endl;   //ok
//     return 0;
// }

// 1. 静态成员函数可以调用非静态成员函数吗？可以  静态函数没有this指针，所以不行
// 2. 非静态成员函数可调用静态的成员函数吗？不行  非静态函数有this指针，静态的成员函数的调用不需要对象
//                                                                           所以不管怎么样都行

// 求1+2+3+...+n
// https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1

// class Sum {
// public:
//     Sum() {
//         _sum += _i;
//         ++_i;
//     }

//     static int GetSum() {
//         // 这里能访问到_sum是因为_sum放到了静态区,可以直接访问
//         return _sum;
//     }

//     //防止重复调用导致的_sum的值错误
//     static void Init() {
//         _i = 1;
//         _sum = 0;
//     }

// private:
//     static int _i;
//     static int _sum;
// };

// // 类内的静态成员变量需要在类外进行定义和初始化，这是因为静态成员属于类本身，而不是类的某个对象，
// // 它们在程序的全局数据区分配内存，并且需要明确的内存分配和初始化。
// // 当你在类内声明静态成员变量时，只是告诉编译器有这样一个静态成员存在，但并没有为其分配内存。
// // 因此，需要在类外进行定义，这时就需要再次指定类型，然后是类名和作用域解析运算符::，最后是变量名和初始值
// int Sum::_i = 1;
// int Sum::_sum = 0;

// class Solution {
// public:
//     int Sum_Solution(int n) {
//         Sum::Init();
//         //利用数组创建了n个Sum类
//         Sum a[n];
//         return Sum::GetSum();
//     }
// };


