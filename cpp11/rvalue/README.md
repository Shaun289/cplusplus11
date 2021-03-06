# [rvalue](https://modoocode.com/227)
- [코드](./rvalue.cpp)

## Copy Elision 복사 생략
- 컴파일러 레벨에서 복사를 생략해버리는 경우를 Copy Elision(복사생략) 이라고 함.

## nullptr
- NULL = 0 이므로 0과 null pointer를 구분할 수 없음
- c++11에서 nullptr 이 추가되었고 확실히 구분됨
- 왜 여기에서 나왔는지 모르겠지만 좋네

## rvalue
- int a = 3 의 3 처럼 주소값을 취할 수 없는 값을 우측값(rvalue)라고 부름
- testCopyElision() 이 코드로는 이동생성자가 호출되는 경우를 확인할 수 없네요. 다른 강의를 찾아봐야할듯 합니다.


# [cprogramming.com/rvalue](https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html)

```cpp
int a;
a = 1 // a is an lvalue

int x;
int& getRef()
{
    return x;
}
getRef() = 4; // 희안한 문법이긴 하지만 암튼 가능은 한다고 치고...

int getVal()
{
    return x;
}
getVal(); // getVasl() is an rvalue. x를 레퍼런스하는게 아니라 임시값임.

string getName()
{
    return "Alex";
}
getName(); // getName() is also an ravlue. 이것도 임시값 rvalue임

const string& name = getName(); // ok. 임시값이지만 수정할거 아니므로,
string& name = getName(); // NOT ok. 임시값을 수정하게 되므로

const string&& name = getName(); // ok
string&& name = getName; // also ok!
```

- 여기까지 알겠음. 근데 이게 어떻게 도움됨? 매개변수로 쓸때 무슨 일이 일어나는지 알 수 있음

```cpp
void printReference(const string& str)
{
    cout << str;
}

void printReference(const string&& str)
{
    cout << str;
}
```

- 이제 const string 레퍼런스를 받는 printReference 함수는 주어진 아무 매개변수나 다 받을 수 있음. 이게 lvalue든 rvalue든. mutable이든 말든. mutable rvalue-reference 빼고(이건 또 뭔소리야...)

```cpp
string me("alex");
printReference(me); // lvalue
printReference(getName()); // rvalue
```

- 이제 임시 객체든 영구 객체든 레퍼런스값을 참조할 수 있는 방법을 가지게 됨. rvalue 레퍼런스는 임시 객체로 향하는 클럽의 백도어같은거임(지루한 클럽일거임). 자 이제 이 방법을 어떻게 쓸지 알아보자.

## move 생성자와 move 할당 연산자 (Move constructor and move assignment operator)
- move 생성자는 copy 생성자랑 비슷함, 객체를 매개변수로 받아서 새로운 인스턴스를 만든다. 하지만 move 생성자는 메모리 재생성을 피한다. 임시 객체를 제공받았기 때문에 이걸 복사하기보다는 move해서 쓴다. (이미 생성된 임시 객체를 갖다 그대로 쓰기때문에 copy를 하지 않아도 된다는 뜻인듯)
- 객체를 move 한다는건 무슨 뜻일까? int같은 기본타입이면 그냥 복사한다. 하지만 포인터라면 새로운 메모리를 할당하고 초기화하기보다, 그냥 포인터를 빼앗아오고 임시 객체의 포인터를 null로 만들어버리면 된다. 임시 객체ㄹ는 더이상 필요하지 않다는 걸 아니까 그거 그냥 쓰는거다.
- rvalue.cpp 의 testMoveConstructor 참조
