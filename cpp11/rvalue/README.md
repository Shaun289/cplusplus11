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