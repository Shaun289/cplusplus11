# [C++11 improvements over C++ 03](http://cplusplus.com/articles/EzywvCM9/)

- cplusplus.com -> articles -> c++11

## About C++11
C++11은 늦은 2011년에 출시된 새로운 C++ 언어 표준입니다. 2003년에 출시된 오래된 C++03 표준을 대체합니다. 자연스럽게 오래된 표준에서 진보를 가져왔고, 몇가지를 이 글에서 설명합니다.

## The revamped auto keyword

장황함은 좋지 않습니다. 주로 코드를 덜 선명하게하기 때문입니다. C에서 남은 auto 키워드는 C++11에서 새로운 의미를 가집니다.: 자동 타입 추론.

코드: [cpp11_auto.cpp](./cpp11_auto.cpp)

```cpp
cbegin과 cend는 const iterator를 반환하는 메소드입니다.
auto를 쓸때는 명시적으로 cbegin cend가 필요합니다.
습관적으로 begin end만 사용했는데 const를 쓸때는 cbegin cend를 써야겠습니다.
```

