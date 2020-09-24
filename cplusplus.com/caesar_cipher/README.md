# [Caesar cipher](http://cplusplus.com/articles/9hvU7k9E/)

- cplusplus.com -> articles -> c++11
- 코드: [caesar_cipher.cpp](./caesar_cipher.cpp)

# Caveat 경고

카이사르 암호화는 숫자와 심볼을 바꾸지 않고 남겨둔채로 알파벳을 회전하여 텍스트를 암호화합니다. 기밀 메시지를 암호화하기 위해 고대에 사용되었으나, 오늘날의 관점에서는 장난감 암호화에 불과합니다.

이 문서의 목적은 카이사르 암호화를 발전시키는게 아니라 영어를 위해 이것을 구현하는데 어떻게 C++ 특징을 사용하는지 보여주는데 있습니다.

## Goal

- char[], std::string과 file 들의 암호화하는 의미를 제공
- 반복자가 동작하는 함수 템플릿을 통해 달성

## Language
C++11, 2011 버전의 C++ 언어 표준

이 문서의 소스코드 스니펫과 전체 프로그램을 성공적으로 컴파일하기 위해서는 **람다함수**, **범위 기반 for() 루프**, 그리고 **리스트 초기화** 를 지원하는 C++ 컴파일러가 필요함.

## 매개변수와 디자인 근거
이 프로그램의 코어 함수는 caesar_cipher() 이고 4개의 매개변수를 가진다.

이름 | 설명
--- | ---
src_begin | source's beginning iterator
src_end | source's end iterator
dest_begin | destination's beginning iterator
shift | 알파벳 밀기를 의미하는 integer

실제 컨테이너를 대신해서 반복자를 전달하는 접근 방식은 두가지 이점이 있다.

1. 이 함수는 컨테이너에 구애받지 않습니다.
2. 함수 구현이 간단합니다.

## 사용 예

- 좋음

```cpp
std::string s("Hello, world!");

caesar_cipher(s.begin(), s.end(), s.begin(), 4); // S == "Lipps, Asvph!"
caesar_cipher(s.begin(), s.end(), s.begin(), -4); // S == "Hello, world!"
```

- 나쁨

```cpp
const std::vector<char> vc{'0', 'b', 'f', 't', 'b', 's'};
std::list<char> lc(vc.size());

caesar_cipher(vc.begin(), vc.end(), lc.begin(), -1); 
// lc = std::list<char>({'C', 'a', 'e', 's', 'a', 'r'})
```

- 이상함

```cpp
const char ca[]{"Sqjzanxwn!"};
std::unique_ptr<char{}> upca(new char[sizeof ca]);

caesar_cipher(std::begin(ca), std::end(ca), upca.get(), 4); 
// std::strcmp(upca.get(), "Wunderbar!") == 0 
```

## Core function source code
전체 프로그램이 필요하면 동작하는 파일이 있으니, 이어지는 섹션은 건너뛰어라.

*Notes:*

- 알파벳이 이동할때 래핑됩니다. 알파벳이 26개이므로 27 시프트는 1 시프트와 같고, 52 시프트는 이동하지 않은 것과 같다는 의미이다.
- 11라인의 목적은 std::rotate에서 사용할 수 있는 shift위 횟수를 줄이기 위함이니다.


주 : 정말 깔끔하게 정리된 문서와 코드입니다. 영어도 엉망이고 굳이 왜 해야하는지 모르겠을 지난번 Pointers and References와 극명하게 비교되네요.