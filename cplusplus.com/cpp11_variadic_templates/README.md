# [C++11 Variadic templates 가변템플릿](http://cplusplus.com/articles/EhvU7k9E/)

- [cplusplus.com](http://cplusplus.com/) -> articles -> c++11
코드: [cpp11_variadic_templates.cpp](./cpp11_variadic_templates.cpp)

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

주 : 그래..이렇게 쓸일이 있겠다...퍽이나



## Reference
[Microsoft 설명서 : 줄임표 및 Variadic 템플릿](https://docs.microsoft.com/ko-kr/cpp/cpp/ellipses-and-variadic-templates?view=vs-2019)