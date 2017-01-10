//
// @file:           callback_member_function
// @author:         cuckoo
// @date:           2016/11/28 19:55:07
// @description:    https://zhuanlan.zhihu.com/p/23952898
// @note
//

#include <iostream>
using std::cout;
using std::endl;

void Func(void(*shit)(), void *argument)
{
    auto new_func = reinterpret_cast<void(*)(int, double, const char *, void*)>(shit);
    new_func(1, 1.2, "Jesus!", argument);
}

struct Callback
{
    int context;
    void Invoke(int a, double b, const char *c)
    {
        cout << context << ", " << a << ", " << b << ", " << c << endl;
    }
};

class A
{
public:
    int a_;
};
class B
{
public:
    int b_;
};
class C : public A, public B { };

int main()
{
    Callback callback{ 200 };
    callback.Invoke(3, 4, "const char *c");


    C c;
    cout << &c << " " << reinterpret_cast<B*>(&c) << " " << static_cast<B*>(&c) << endl;

    return 0;
}
