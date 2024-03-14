#include <cstdint>
#include <iostream>
#include <memory>

class A
{
  private:
    int32_t _value;
  public:
    A() : _value(0) {}
    A(int32_t value) : _value(value) {}

    int32_t value() const { return _value; }

    void operator=(A rhs) { _value = rhs.value(); }
};

class B
{
  private:
    A _a;

  public:
    B() : _a() {}
    void setA(A& a) { _a = a; }
    int32_t value() const { return _a.value(); }
};

class C
{
  private:
    std::unique_ptr<A> _a;

  public:
    C() : _a(std::make_unique<A>()) {}
    void setA(A& a) { A& aa = *(_a.get()); aa = a; }
    int32_t value() const { return _a->value(); }
};

template<typename T>
void outerFunc(T& t)
{
  A a(10);

  t.setA(a);
}

int main(int, char**)
{
  B b;
  outerFunc<B>(b);

  C c;
  outerFunc<C>(c);

  std::cout << "b=" << b.value() << std::endl;
  std::cout << "c=" << c.value() << std::endl;

  return 0;
}
