# [Pointers and References](http://cplusplus.com/articles/1075fSEw/)

- [cplusplus.com](http://cplusplus.com/) -> articles -> c++11
- 파일명 : [pointers_and_refs.cpp](./pointers_and_refs.cpp)


포인터와 레퍼런스. 컴파일러가 진짜 신경쓰는가?

간단한 실험을 해보자. 포인터와 레퍼런스를 이해하는데 한번만 해봐도 도움될것이다.

두개의 간단한 함수를 선언하자. 하지만 int& 버전만 사용하자.

```cpp
// void some_function(int* i) { cout << "\nvalue is " << *i << endl;};
void some_function(int& i) { cout << "\nvalue is " << i << endl;};
```

이 차이는 하나는 정수의 레퍼런스를 가져오고 다른 하나는 포인터를 가져온다. 아직은 간단하고 좋다. 이제 포인터를 사용해서 함수를 호출해보자.

초기화하자. 이건 그냥 fp를 re-cast하는 것 뿐이다. 이 예제 외에는 말이 안된다. 이제 f는 일부 바이트에 대한 포인터이다. 더이상 함수에 가리키는 포인터를 더이상 모른다.

```cpp
char* fp = reinterpret_cast<char*>(&some_function);
int ii = 5;
reinterpret_cast<void(*)(int&)>(fp)(ii);
```

5를 출력할것이다.

문제없고 심플함.

이번엔 좀 바꿔서 해보자.

```cpp
reinterpret_cast<void(*)(int*)>(fp)(&ii);
```

완전히 똑같이 5를 출력한다. 같은 함수를 호출하기 때문이다. int&가 아니라 int*를 사용하도록 cast했는데? 함수 선언은 int&인데?

처음엔 제대로 된 타입을 썼고 &ii를 쓰지 않았다. 두번째 케이스는 int*로 캐스트했기때문에 &ii 로 포인터로 바꿔서 불렀다.

이 간단한 예제에서 컴파일러가 레퍼런스를 포인터로 호출하는지 상관하지 않는다는 것을 보여준다. 왜냐하면 int&가 int*로 바뀌는 것 뿐이다.

다른말로 하면 컴파일러는 보이는 것만 신경쓴다.

```cpp
void some_function(int* i) { cout << "\nvalue is " << *i << endl;};
```

이렇게 써도

```cpp
void some_function(int& i) { cout << "\nvalue is " << i << endl;};
```

레퍼런스와 함께 포인터를 사용하는 것은 포인터를 사용한거로 바꿀수 있다.

주 : 구글 번역기도 못하는 엉터리 영어로 써놨네요. 진짜 이해하고 번역하기 힘들어서 저도 대충했네요 ㅡ.ㅡ 

cpp11과 도 그다지 상관없는 내용이고.. 이게 왜 여기있는지... 

포인터를 정말 많이 쓰다보면 느끼게 되는 내용입니다. 

이 내용을 포인터와 레퍼런스를 배우는 초보들에게 가르치려 했다간 포기하게 만드는 효과밖에 없겠네요.
