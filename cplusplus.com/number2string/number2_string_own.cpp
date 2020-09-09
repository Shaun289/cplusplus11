#include <string.h>
#include <stdio.h>

// 문자 뒤집기
static void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// itoa: 숫자를 문자 s로 변환
static void own_itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n; /* 양수로 바꿈 */
    i = 0;
    do {
        s[i++] = n%10 + '0';    // 숫자에 '0'를 더함
    } while ((n /= 10) > 0);    // 사용한 숫자는 삭제
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

// atoi: 문자s를 숫자로 변환
// 음수에 관한 처리는 안되어있음
static int own_atoi(char s[])
{
    int i = 0;
    int n = 0;
    bool sign = false;
    if (s[i++] == '-')
        sign = true;
    for (; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10*n + (s[i] - '0');
    if (sign)
        n = -n;
    return n;
}

int main()
{
    int n = 12345;
    char s[32];
    own_itoa(n, s);
    printf("%s\n", s);

    n = -54321;
    own_itoa(n, s);
    printf("%s\n", s);

    strcpy(s, "12345");
    n = own_atoi(s);
    printf("%d\n", n);

   strcpy(s, "-54321");
    n = own_atoi(s);
    printf("%d\n", n);

    return 0;
}