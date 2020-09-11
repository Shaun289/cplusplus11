# [C++11 improvements over C++ 03](http://cplusplus.com/articles/EzywvCM9/)

- cplusplus.com -> articles -> c++11
코드: [cpp11_improvements.cpp](./cpp11_improvements.cpp)

## About C++11
C++11은 늦은 2011년에 출시된 새로운 C++ 언어 표준입니다. 2003년에 출시된 오래된 C++03 표준을 대체합니다. 자연스럽게 오래된 표준에서 진보를 가져왔고, 몇가지를 이 글에서 설명합니다.

## The revamped auto keyword

장황함은 좋지 않습니다. 주로 코드를 덜 선명하게하기 때문입니다. 

그래서 C에서 남은 auto 키워드는 C++11에서 새로운 의미를 가집니다. : 자동 타입 추론.

코드내 함수 : cpp11_auto()

```cpp
cbegin과 cend는 const iterator를 반환하는 메소드입니다.
auto를 쓸때는 명시적으로 cbegin cend가 필요합니다.
습관적으로 begin end만 사용했는데 const를 쓸때는 cbegin cend를 써야겠습니다.
```

## Range-based for()
STL 컨테이너 내용의 반복문은 매우 일반적인 동작입니다.

C++11 은 예상되는 iterator를 반환하는 begin()과 end()를 가진 어떤 반복도 할 수 있는 특별한 for 문을 제공합니다.

일반 C 배열에서도 동작합니다. ~~이건 몰랐네요.~~

코드내 함수 : cpp11_for()

## Initializer lists
C++03 에서 컨테이너는 잘 쓰던 오래된 C스타일 배열처럼 "자연스럽게" 초기화하지 못합니다. 이게 바뀌었습니다.

~~C++03에서 이것때문에 짜증스러웠던 적이 많았죠.~~

코드내 함수 : cpp11_initializer()

코드내 함수 : cpp11_initializer_complex()

## C++ Arrays
*이건 추가이지 진보가 아닙니다만, 이 문서에 포함하기로 결정했습니다.*

C++11은 C 배열을 대체하는 std::array 를 제공합니다. 고정사이즈에 가벼워 가변 크기의 std::vector의 대안입니다.

코드내 함수 : cpp11_array()

참고자료 : [array container 정리 및 사용법](https://blockdmask.tistory.com/332)