# [Lambda function](https://modoocode.com/196)

- [Source code](./lamdba.cpp)

```cpp
[my_mod](int v_) ->int {return v_ % my_mod;}
```

- 람다함수의 문법은 위와 같습니다. 자바스크립트 해보신분들은 많이 해보셨을듯
  - my_mode : introducer 개시자, 외부 변수를 넣으면 이를 람다함수 내부에서 쓸수 있게 해줌
  - int v_ : parameters
  - ->int : return type
  - {} : statement
- introducer 만 제외하고는 익숙합니다.
- 기본적으로 introducer는 read-only 입니다. 다음과 같이 하면 컴파일 단계에서 에러가 발생하죠.

```cpp
lambda.cpp:15:24: error: assignment of read-only variable ‘my_mod’
   15 |     [my_mod]() {my_mod -= 4; }();
      |                 ~~~~~~~^~~~
```

## [transform](http://cplusplus.com/reference/algorithm/transform/?kw=transform)
- 람다함수에는 transform 이 빠질 수 없죠.
- UnaryOperator op 에 람다함수를 넣어주면 됩니다. 참 쉽죠?

```cpp
template <class InputIterator, class OutputIterator, class UnaryOperator>
  OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op)
{
  while (first1 != last1) {
    *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
    ++result; ++first1;
  }
  return result;
}
```

