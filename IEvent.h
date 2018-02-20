#ifndef IEVENT_H
#define IEVENT_H
#endif // IEVENT_H_INCLUDED
class IPS2XEvent
{
public:
    //虚成员函数=0;表示本类不对这个成员函数进行实现，即该成员函数没有函数体{ }，这种函数就叫纯虚函数。
    //一个类中只要有一个成员函数是纯虚函数，就成了不能实例化的虚类，相当于接口，只能给派生类继承，让派生类来进行函数覆盖重写这个虚方法。
    virtual void OnPressed(int keyValue) = 0;
};
