# [C++11 Variadic templates 가변템플릿](http://cplusplus.com/articles/EhvU7k9E/)

- [cplusplus.com](http://cplusplus.com/) -> articles -> c++11


## Introduction
C++11 가능성의 이전에는 인스턴스 함수 객체(functors)와 튜플 을 구현할때 템플릿 사용성이 꽤 제한되었습니다. 이전 C++ 표준에서 이런 것들을 구현할때는 전처리 메타 프로그래밍을 쓰지않으려면 종종 비슷한 코드가 반복되는게 필요했습니다. 그러나 고맙게도 템플릿을 이용한 새로운 기능인 가변 템플릿을 사용하면 쉽고 명료하고 보다 메모리 효율적이 되었습니다.

D프로그래밍언어에서 가변 템플릿을 지원함에도 불구하고, C++11 표준에서 제공하는 가변 템플릿만 이 문서에서 다룰 것입니다. 그래서 D프로그래밍의 가변 템플릿에 대한 지식은 이 문서를 읽거나 이해하는데 필요하지 않습니다. 그러나 이 문서를 읽는 독자가 클래스&함수 템플릿이 무엇인지 어떤게 선언하고 정의하고 사용하는지에 대해 이해하고 있다고 가정합니다.

## What is a variadic template?
가변 템플릿은 템플릿 매개변수의 임의의 숫자를 받는 템플릿입니다. 클래스들과 함수들 모두 가변이 될 수 있습니다. 

가변 클래스 템플릿은 다음과 같습니다.

```cpp
template<typename... Arguments>
class VariadicTemplate;
```

다음의 어떤 방식으로도 객체를 생성하는 것이 가능합니다.

```cpp
VariadicTemplate<double, float> instance;
VariadicTemplate<bool, unsigned short int, long> instance;
VariadicTemplate<char, std::vector<int>, std::string, std::vector<long long>> instance;
```

매개변수의 갯수를 0으로 할 수 있습니다.

```cpp
VariadicTemplate<> instance;
```

하지만 다으모가 같이 템플릿을 만들게 되면

```cpp
template<typename T, typename... Arguments>
class VariadicTemplate;
```

다음과 같이 기본 타입이 초기화되어있지 않다면, 반드시 (typename T를 위한) 한개 이상의 매개변수를 설정해야합니다. 

```cpp
template<typename T=int, typename... Arguments>
class VariadicTemplate;
```

## Syntax - the ellipsis operator (...): 줄임표 연산자
줄임표 연산자(...)는 C++에서 다른 컨텍스트에서 사용하는 연산자입니다. C의 줄임표 메커니즘에서 유래했습니다. 이 메커니즘에서 개발자는 다양한 수의 매개변수를 받아들이는 함수를 생성할 수 있습니다. 아마도 C와 C++에서 이 메카니즘의 이점을 가져가는 가장 유명한 함수는 c표준라이브러리의 printf 함수입니다.

```c
int printf(const char* format, ... );
```

줄임표 메커니즘은 매크로 전처리에서도 사용할 수 있습니다. 다양한 수의 매개변수를 가져가는 매크로를 줄임표 매크로라고 합니다.

```c
#define VARIADIC_MACRO(...)
```

C++에서는 이 줄임표 연산자가 예외처리라는 다른 컨텍스트에서 새로운 의미를 가집니다. 이 연산자는 try 다음의 catch 블럭에서 사용됩니다.

```c++
try {
    // Try block
}
catch (...) {
    // Catch block
}
```

주 : 줄임표로 받는 예외를 확인하는 방법은 [std::current_exception](http://cplusplus.com/reference/exception/current_exception/) 에서 확인할 수 있습니다.

줄임표 연산자는 try 블럭으로부터 발생한 어떤 타입이든 상관없이 어떤 예외도 받을 수 있는 catch 블럭을 매개변수로 지정합니다.

C++11에서 가변 템플릿은 이 연산자의 다른 의미를 가져옵니다. 이 연산자는 이미 기술된 가변 메카니즘과 비슷하게 동작합니다만 조금 더 복잡합니다.

```c++
template<typename... Arguments>
void SampleFunction(Arguments... parameters);
```

여기 함수 템플릿입니다. 가변 템플릿 매개변수의 내용을 매개변수 팩이라고 부릅니다. 이 팩들은 함수 매개변수 안에서 언팩됩니다. 예를 들어 이전 가변 함수 템플릿을 부른다면...

```cpp
SampleFunction<int, int>(16, 24);
```

다음 함수와 같습니다.

```cpp
template<typename T, typename U>
void SampleFunction(T param1, U param2);
```

## Syntax - sizeof 연산자 (sizeof...):
가변템플릿을 사용하는 또다른 연산자는 sizeof... 연산자이다. 타입의 사이즈를 확인하는 sizeof 연산자와 다르게, sizeof... 연산자는 가변템플릿에게 주어진 타임의 양응 확인하는데 쓰인다. 

```cpp
template<typename... Arguments>
class VariadicTemplate{
    private:
    static const unsigned short int size = sizeof...(Arguments);
}
```

## Syntax - 두 줄임표를 함께 (......):
어떤 환경에서는 두 줄임표 연산자가 함께 (......) 있을수 있습니다. 이 두 연산자들은 다음과 같이 분리될 수도 있습니다. (... ...)

그러나 아마도 가장 명확한 방법은 쉼표를 사용해서 구분하는 방법입니다(..., ...). 마침표가 있든 없든 모두 가능합니다.

이런 종류의 문법은 줄임표 메커니즘을 사용하는 가변함수 템플릿에서 나타납니다.

```cpp
template<typename... Arguments>
void SampleFunction(Arguments......) {

}
```

## 가변 템플릿의 사용 - 상속 & 초기화 리스트:
클래스에서 가변 템플릿은 상속과 리스트 초기하와 함께 사용할 수 있습니다. 가변 템플릿의 이점을 가져가는 상속은 아래와 같은 장점이 있습니다.

```cpp
template<typename... BaseClasses>
class VariadicTemplate : Public BaseClasses...
```

주 : class A를 상속받는 B,C,D 가 있다고 할때 필요에 따라 B,C,D를 상속받을 수 있는 E를 만들수 있겠네요. 신박하네요!

그리고 만약 템플릿 매개변수로 주어진 모든 부모 클래스의 생성자를 부르는 초기화 리스트 클래스 안에서 생성자를 만든다면, 아래와 같이 할 수 있습니다. 

```cpp
template<typename...BaseClasses>
class VariadicTemplate : public BaseClasses... {
public:
    VariadicTemplate(BaseClasses&&... base_classes) : BaseClasses(base_classes)... {

    }
};
```

여기서 보는것처럼, C++11에서 생성자의 매개변수 리스트라는 새로운 연산자가 있습니다. - *an rvalue operator(&&)*, rvalue 참조를 허용합니다. 이 문서는 이 연산자를 커버하지 않습니다만, 이 연산자를 어떻게 사용하는지에 대한 정보는 [C++ Rvalue References Explained
](http://thbecker.net/articles/rvalue_references/section_01.html)를 참조하세요.

# 가변 템플릿의 사용 - 가변 클래스 템플릿 전문화(?):
클래스 템플릿처럼, 가변 클래스 템플릿도 전문화될 수 있습니다. 템플릿과 함께 전문화는 다음과 같습니다:

```cpp
template<typename T>
class Template{
public:
    void SampleFunction(T param) {

    }
};

```

하지만 가변 템플릿과 함께 다음과 같습니다:

```cpp
template<typename... Arguments>
class VariadicTemplate {
public:
    void SampleFunction(Arguments... params) {

    }
};

template<>
class VariadicTemplate<double, int long> {
public:
    void SampleFunction(double param1, int param2, long param3) {

    }
};
```

주 : 가변 템플릿을 정의해놓고 특수한 매개변수에 대해서는 전문화하여 따로 구현할 수 있다는 뜻입니다.

주의 : 아직 몇몇 컴파일러는 가변 클래스 템플릿 전문화를 지원하지 않거나 구현이 완료되지 않았습니다.

## 같이보기:
가변 템플릿을 활용하는 C++11 표준 클래스 템플릿에 관심이 있다면, 다음의 튜플에 대해 확인하세요.
[std::tuple](http://www.cplusplus.com/reference/tuple/tuple/)

가변 템플릿이 유용한 또다른 필드는 *delegates* 입니다. 만약 **managed C++** and/or C# 에 익숙하다면, C++ delegates는 문제가 아닐것입니다. 

## 결론
템플릿은 C++에서 강력한 특징이었습니다. 이제 가변 템플릿의 소개로 템플릿은 더 강력하다는 것을 증명하게 됩니다. 가변 템플릿은 *delegate*와 *tuple*을 구현하는 믿을수 있는 솔루션입니다. 그리고 C스타일의 줄임표 메커니즘 대신에 가변 템플릿은 타입안전한 솔루션으로 대체할 것입니다.

## 컴파일러 지원에 관한 더 많은 정보
만약 컴파일러의 지원에 잘 모르거나 익숙하지 않으면 아래 링크를 방문하세요.
http://wiki.apache.org/stdcxx/C++0xCompilerSupport

## Reference
[Microsoft 설명서 : 줄임표 및 Variadic 템플릿](https://docs.microsoft.com/ko-kr/cpp/cpp/ellipses-and-variadic-templates?view=vs-2019)


