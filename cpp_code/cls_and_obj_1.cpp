// -------------------------类的定义---------------------------------

// c++中在结构体中可以定义函数，也就是方法，不过通常使用类来定义(struct和class都可以定义类)，和python类似,

// 封装特性，类比python:
// public修饰的成员在类外可以直接被访问
// protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
// 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
// class的默认访问权限为private，struct为public(因为struct要兼容C)

// #include <iostream>
// using namespace std;
// class Student {
//     public:
//         void ShowInfo() {
//             cout << _name << endl;
//             cout << _age << endl;
//             cout << stuid << endl;
//         }
//     private:    //一般成员变量都是比较隐私的
//         char* _name;
//         int _age;
//         int stuid;
// };

//若是在类中声明函数，在实现函数的时候要指定函数的作用域(指一下在哪里)，如：
// void Student::ShowInfo() {}      //这里指定了ShowInfo函数是在Student这个类当中的

// -------------------------类的实例化---------------------------------

// #include <iostream>
// using namespace std;
// class Stack {
//     public:
//         void Push();
//         void Pop();
//         void Empty();   //这里是声明

//     private:
//         int* _a;
//         int _size;
//         int _capacity;  //这里是声明
// };
// //声明就是承诺要做，但是还没有做，定义是已经落地了
// void Stack::Push() {
//     //......;                   //这里就是定义
// } 

// //-----没有成员变量的类------
// class A1 {
//     void func(){}
// };

// class A2 {};

// int main() {
//     //实例化出对象
//     Stack st;

//     cout << sizeof(st) << endl; //16
//     //说明一个类实例化出N个对象，每一个对象的成员变量储存不同的值，而调用的函数是同一个，
//     //如果都储存函数，则浪费了空间,函数存储在了公共代码区

//     //计算实例化对象的大小就和结构体一样算就好了，要考虑内存对齐

//     cout << sizeof(A1) << endl; //1
//     cout << sizeof(A2) << endl; //1
//     //没有成员变量的类大小为1，开辟一个字节不是为了存储数据，而是为了占位

//     return 0;
// }


// -------------------------隐含的this指针---------------------------------

// #include <iostream>
// using namespace std;
// class Data{
//     public:
//         void Init(int year, int month, int day) {
//             _year = year;
//             _month = month;
//             _day = day;
//         }
//         //这里的函数实际上是这样的void Show(Data* this),this 指针指向调用成员函数的对象
//         //和python中的实例方法类似
//         // void Show(Data* this) {
//         //     cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//         // }

//         void Show() {
//             cout << _year << "-" << _month << "-" << _day << endl;
//         }
//     private:
//     //加下划线是为了区分成员变量和其他的变量
//         int _year;
//         int _month;
//         int _day;
// };
// int main() {
//     Data da;
//     da.Init(2025, 6, 11);
//     da.Show();
//     return 0;
// }


// #include <iostream>
// using namespace std;
// class A {
//     public:
//         void Print() {
//             cout << _a << endl;
//         }

//         void Show() {
//             cout << "show" << endl;
//         }

//     private:
//         int _a;
// };

// int main() {
//     A* p = NULL;
//     p->Print(); //崩溃
//     p->Show();  //正常运行
//     // 成员函数在公共的代码段，p->Show()并没有访问p中的成员变量，没有解引用，所以可以正常运行
//     return 0;
// }