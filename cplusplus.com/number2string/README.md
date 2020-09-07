# Converting numbers to strings and strings to numbers

- cplusplus.com -> articles -> c++11
- http://cplusplus.com/articles/D9j2Nwbp/

## C++ stringstreams
C++98 에 해당하는 방법입니다.

### Number to String
파일명 : number2_string_ss.cpp

투스텝으로 변경합니다.

1. 출력할 숫자를 스트림으로
2. 스트림에서 string 가져오기

### 커스텀 포매팅
0.12를 "0,120" 으로 변환하여 string을 만듭니다.

class numpunct 
- http://cplusplus.com/reference/locale/numpunct/?kw=numpunct
- https://docs.microsoft.com/ko-kr/cpp/standard-library/numpunct-class?view=vs-2019
- number puctuation : 숫자 구두법
- 각 나라마다 숫자표기법이 달라서 만들어진 클래스
- 예제 코드에서는 이 클래스를 상속받아서 do_decimal_point를 재구현

std::fixed
- http://cplusplus.com/reference/ios/fixed/?kw=fixed
- 부동소수점 표기법을 부동 소수점으로 표기
- cplusplus.com 의 예제를 보면 이해된다.

std::setprecision
- http://cplusplus.com/reference/iomanip/setprecision/ 
- 부동소수점 숫자 정밀도를 설정
- 이것도 cplusplus.com 예제를 보면 이해된다.